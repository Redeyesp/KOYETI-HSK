#include "PartnerLink.h"
#include "PartnerConfig.h"

#include <WiFi.h>
#include <esp_wifi.h>
#include <cstring>

PartnerLink* PartnerLink::_instance = nullptr;

namespace
{
constexpr uint32_t HEART_MAGIC = 0x4B485254UL;   // "KHRT"
constexpr uint32_t PAIR_KEY = 0x9F6C21D8UL;
constexpr uint8_t HEART_VERSION = 2;
constexpr uint8_t HEART_TYPE = 1;

constexpr uint8_t BROADCAST_MAC[6] =
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

constexpr uint8_t SEND_COPIES = 3;
constexpr unsigned long COPY_GAP_MS = 80UL;
constexpr unsigned long STATUS_EVERY_MS = 5000UL;

struct __attribute__((packed)) HeartPacket
{
    uint32_t magic;
    uint32_t pairKey;
    uint8_t version;
    uint8_t type;
    uint8_t senderId;
    uint16_t sequence;
};

bool sameMac(const uint8_t* a, const uint8_t* b)
{
    return memcmp(a, b, 6) == 0;
}

void printMac(const uint8_t* mac)
{
    for (uint8_t i = 0; i < 6; ++i)
    {
        if (i > 0) Serial.print(':');
        if (mac[i] < 16) Serial.print('0');
        Serial.print(mac[i], HEX);
    }
}
}

void PartnerLink::begin()
{
    _instance = this;

    Serial.println();
    Serial.print("[PartnerLink] ");
    Serial.print(DEVICE_NAME);
    Serial.println(" ESP-NOW broadcast-v2 starting");

    // Keep the radio in station mode but NEVER join an access point.
    // This prevents a remembered Wi-Fi network from changing our channel.
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(false);
    WiFi.disconnect(false, false);
    delay(150);

    const esp_err_t channelResult =
        esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);

    if (channelResult != ESP_OK)
    {
        Serial.print("[PartnerLink] Cannot set channel, err=");
        Serial.println(static_cast<int>(channelResult));
        return;
    }

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("[PartnerLink] ESP-NOW init failed");
        return;
    }

    esp_now_register_recv_cb(PartnerLink::receiveCallback);

    // Send by broadcast instead of unicast.
    // The receiver still checks the REAL sender MAC and pair key,
    // so only KOYETI <-> KOKORO accepts the heart.
    esp_now_peer_info_t broadcastPeer = {};
    memcpy(broadcastPeer.peer_addr, BROADCAST_MAC, 6);
    broadcastPeer.channel = ESPNOW_CHANNEL;
    broadcastPeer.ifidx = WIFI_IF_STA;
    broadcastPeer.encrypt = false;

    if (esp_now_is_peer_exist(BROADCAST_MAC))
    {
        esp_now_del_peer(BROADCAST_MAC);
    }

    const esp_err_t peerResult = esp_now_add_peer(&broadcastPeer);

    if (peerResult != ESP_OK)
    {
        Serial.print("[PartnerLink] Add broadcast peer failed, err=");
        Serial.println(static_cast<int>(peerResult));
        return;
    }

    _ready = true;

    Serial.print("[PartnerLink] Local MAC: ");
    Serial.println(WiFi.macAddress());

    Serial.print("[PartnerLink] Accept only partner: ");
    printMac(PARTNER_MAC);
    Serial.println();

    Serial.print("[PartnerLink] Channel: ");
    Serial.println(ESPNOW_CHANNEL);
    Serial.println("[PartnerLink] ESP-NOW broadcast-v2 READY <3");
}

void PartnerLink::update()
{
    if (!_ready)
    {
        return;
    }

    const unsigned long now = millis();

    // Keep both radios pinned to exactly the same channel.
    uint8_t currentChannel = 0;
    wifi_second_chan_t secondChannel = WIFI_SECOND_CHAN_NONE;
    esp_wifi_get_channel(&currentChannel, &secondChannel);

    if (currentChannel != ESPNOW_CHANNEL)
    {
        Serial.print("[PartnerLink] Channel drift ");
        Serial.print(currentChannel);
        Serial.print(" -> ");
        Serial.println(ESPNOW_CHANNEL);

        esp_wifi_set_channel(ESPNOW_CHANNEL, WIFI_SECOND_CHAN_NONE);
        currentChannel = ESPNOW_CHANNEL;
    }

    if (_pendingCopies > 0 &&
        static_cast<long>(now - _nextCopyMs) >= 0)
    {
        sendPendingCopy(now);
    }

    if (now - _lastStatusMs >= STATUS_EVERY_MS)
    {
        _lastStatusMs = now;

        Serial.print("[PartnerLink] ALIVE | ready=YES | MAC=");
        Serial.print(WiFi.macAddress());
        Serial.print(" | channel=");
        Serial.println(currentChannel);
    }
}

void PartnerLink::sendHeart()
{
    if (!_ready)
    {
        Serial.println("[PartnerLink] Cannot send heart: ESP-NOW not ready");
        return;
    }

    _pendingSequence = ++_sequence;
    _pendingCopies = SEND_COPIES;
    _nextCopyMs = millis();

    Serial.print("[PartnerLink] Heart queued #");
    Serial.print(_pendingSequence);
    Serial.print(" x");
    Serial.println(SEND_COPIES);
}

void PartnerLink::sendPendingCopy(unsigned long now)
{
    HeartPacket packet = {};
    packet.magic = HEART_MAGIC;
    packet.pairKey = PAIR_KEY;
    packet.version = HEART_VERSION;
    packet.type = HEART_TYPE;
    packet.senderId = DEVICE_ID;
    packet.sequence = _pendingSequence;

    const uint8_t copyNumber =
        static_cast<uint8_t>(SEND_COPIES - _pendingCopies + 1);

    const esp_err_t result = esp_now_send(
        BROADCAST_MAC,
        reinterpret_cast<const uint8_t*>(&packet),
        sizeof(packet)
    );

    Serial.print("[PartnerLink] TX heart #");
    Serial.print(packet.sequence);
    Serial.print(" copy ");
    Serial.print(copyNumber);
    Serial.print("/");
    Serial.print(SEND_COPIES);

    if (result == ESP_OK)
    {
        Serial.println(" -> queued OK");
    }
    else
    {
        Serial.print(" -> ERROR ");
        Serial.println(static_cast<int>(result));
    }

    if (_pendingCopies > 0)
    {
        --_pendingCopies;
    }

    _nextCopyMs = now + COPY_GAP_MS;
}

bool PartnerLink::takeIncomingHeart()
{
    if (!_incomingHeart)
    {
        return false;
    }

    _incomingHeart = false;
    return true;
}

bool PartnerLink::ready() const
{
    return _ready;
}

#if ESP_ARDUINO_VERSION_MAJOR >= 3
void PartnerLink::receiveCallback(
    const esp_now_recv_info_t* info,
    const uint8_t* data,
    int len
)
{
    if (_instance != nullptr && info != nullptr)
    {
        _instance->onReceive(info->src_addr, data, len);
    }
}
#else
void PartnerLink::receiveCallback(
    const uint8_t* mac,
    const uint8_t* data,
    int len
)
{
    if (_instance != nullptr)
    {
        _instance->onReceive(mac, data, len);
    }
}
#endif

void PartnerLink::onReceive(
    const uint8_t* mac,
    const uint8_t* data,
    int len
)
{
    if (mac == nullptr || data == nullptr)
    {
        return;
    }

    if (!sameMac(mac, PARTNER_MAC))
    {
        return;
    }

    if (len != static_cast<int>(sizeof(HeartPacket)))
    {
        Serial.print("[PartnerLink] RX from partner but wrong size=");
        Serial.println(len);
        return;
    }

    HeartPacket packet = {};
    memcpy(&packet, data, sizeof(packet));

    if (packet.magic != HEART_MAGIC ||
        packet.pairKey != PAIR_KEY ||
        packet.version != HEART_VERSION ||
        packet.type != HEART_TYPE ||
        packet.senderId != PARTNER_DEVICE_ID)
    {
        Serial.println("[PartnerLink] RX partner packet rejected");
        return;
    }

    // We transmit the same heart three times for reliability.
    // Only animate once for a given sequence number.
    if (packet.sequence == _lastReceivedSequence)
    {
        return;
    }

    _lastReceivedSequence = packet.sequence;
    _incomingHeart = true;

    Serial.print("[PartnerLink] RX HEART #");
    Serial.print(packet.sequence);
    Serial.print(" from ");
    printMac(mac);
    Serial.println(" <3");
}

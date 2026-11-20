#ifndef PARTNER_LINK_H
#define PARTNER_LINK_H

#include <Arduino.h>
#include <esp_now.h>

class PartnerLink
{
public:
    void begin();
    void update();

    // Called only for a heart created on THIS device.
    void sendHeart();

    // Returns true once for each newly received partner heart.
    bool takeIncomingHeart();

    bool ready() const;

private:
    void sendPendingCopy(unsigned long now);
    void onReceive(const uint8_t* mac, const uint8_t* data, int len);

#if ESP_ARDUINO_VERSION_MAJOR >= 3
    static void receiveCallback(
        const esp_now_recv_info_t* info,
        const uint8_t* data,
        int len
    );
#else
    static void receiveCallback(
        const uint8_t* mac,
        const uint8_t* data,
        int len
    );
#endif

    static PartnerLink* _instance;

    volatile bool _incomingHeart = false;
    bool _ready = false;

    uint16_t _sequence = 0;
    uint16_t _lastReceivedSequence = 0;

    uint16_t _pendingSequence = 0;
    uint8_t _pendingCopies = 0;
    unsigned long _nextCopyMs = 0;
    unsigned long _lastStatusMs = 0;
};

#endif

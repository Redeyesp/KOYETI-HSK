#ifndef PARTNER_CONFIG_H
#define PARTNER_CONFIG_H

#include <Arduino.h>

constexpr char DEVICE_NAME[] = "KOYETI";
constexpr uint8_t DEVICE_ID = 1;
constexpr uint8_t PARTNER_DEVICE_ID = 2;
constexpr uint8_t ESPNOW_CHANNEL = 1;

constexpr uint8_t PARTNER_MAC[6] =
    {0x14, 0x63, 0x93, 0xC8, 0x8E, 0xE0};

#endif

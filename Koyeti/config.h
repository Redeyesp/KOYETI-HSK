#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Shown on the web flasher page; bump it when you publish a new build.
#define FW_VERSION "2.0.0"

constexpr uint8_t OLED_SDA_PIN = 8;
constexpr uint8_t OLED_SCL_PIN = 9;
constexpr uint8_t TOUCH_PIN    = 7;

constexpr uint16_t BOOT_TIME_MS        = 900;
constexpr uint16_t TOUCH_DEBOUNCE_MS   = 30;
constexpr uint16_t LONG_PRESS_MS       = 800;
constexpr uint16_t DOUBLE_TAP_MS       = 350;

//--------------------------------------------------
// Hanzi
//--------------------------------------------------
constexpr uint8_t HANZI_SCALE = 3;  // 16x16 Unifont bitmap -> 48x48 on screen

//--------------------------------------------------
// Blink Animation
//--------------------------------------------------
// Normal
//   ↓110ms
// Half
//   ↓180ms
// Closed
//   ↓110ms
// Half
//   ↓
// Normal

constexpr uint16_t BLINK_HALF_MS        = 110;
constexpr uint16_t BLINK_CLOSED_MS      = 180;

constexpr uint16_t BLINK_MIN_INTERVAL_MS = 4500;
constexpr uint16_t BLINK_MAX_INTERVAL_MS = 9000;

//--------------------------------------------------
// Sleep
//--------------------------------------------------

constexpr uint32_t IDLE_TO_SLEEP_MS = 30000UL;

constexpr uint16_t SLEEPY_FRAME1_MS = 850;
constexpr uint16_t SLEEPY_FRAME2_MS = 1200;
constexpr uint16_t SLEEP_Z_FRAME_MS = 160;  // 8-frame procedural Z loop

//--------------------------------------------------
// Celebration
//--------------------------------------------------
// Happy 400ms
// Fire1 180ms
// Fire2 180ms
// Fire1 180ms
// Fire2 180ms
// Fire1 180ms
// Fire2 180ms
// Happy 500ms

constexpr uint16_t CELEBRATION_HAPPY_START_MS = 400;
constexpr uint16_t CELEBRATION_FIRE_FRAME_MS  = 180;
constexpr uint16_t CELEBRATION_HAPPY_END_MS   = 500;

#endif
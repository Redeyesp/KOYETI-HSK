#ifndef TOUCH_H
#define TOUCH_H

#include <Arduino.h>

enum class TouchEvent : uint8_t
{
    None,
    SingleTap,
    DoubleTap,
    LongPress
};

class Touch
{
public:
    void begin();
    TouchEvent update();

private:
    bool _stableState = false;
    bool _rawState = false;
    bool _longReported = false;
    uint8_t _tapCount = 0;
    unsigned long _lastRawChangeMs = 0;
    unsigned long _pressStartMs = 0;
    unsigned long _lastReleaseMs = 0;
};

#endif

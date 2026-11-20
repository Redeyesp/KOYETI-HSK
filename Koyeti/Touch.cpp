#include "Touch.h"
#include "config.h"

void Touch::begin()
{
    pinMode(TOUCH_PIN, INPUT);
    _rawState = digitalRead(TOUCH_PIN) == HIGH;
    _stableState = _rawState;
    _lastRawChangeMs = millis();
}

TouchEvent Touch::update()
{
    const unsigned long now = millis();
    const bool raw = digitalRead(TOUCH_PIN) == HIGH;

    if (raw != _rawState)
    {
        _rawState = raw;
        _lastRawChangeMs = now;
    }

    if (_rawState != _stableState && now - _lastRawChangeMs >= TOUCH_DEBOUNCE_MS)
    {
        _stableState = _rawState;

        if (_stableState)
        {
            _pressStartMs = now;
            _longReported = false;
        }
        else
        {
            if (!_longReported)
            {
                ++_tapCount;
                _lastReleaseMs = now;

                if (_tapCount >= 2)
                {
                    _tapCount = 0;
                    return TouchEvent::DoubleTap;
                }
            }
        }
    }

    if (_stableState && !_longReported && now - _pressStartMs >= LONG_PRESS_MS)
    {
        _longReported = true;
        _tapCount = 0;
        return TouchEvent::LongPress;
    }

    if (_tapCount == 1 && now - _lastReleaseMs >= DOUBLE_TAP_MS)
    {
        _tapCount = 0;
        return TouchEvent::SingleTap;
    }

    return TouchEvent::None;
}

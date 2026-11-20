#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

enum class Face : uint8_t
{
    Normal,
    Half,
    Closed,
    Happy,
    Fire1,
    Fire2,
    Sleepy1,
    Sleepy2,
    Sleepy3,
    Heart1,
    Heart2
};

class Display
{
public:
    void begin();
    void showBoot();
    void showFace(Face face);
    void showSleepingFrame(uint8_t frame);
    // Large hanzi (16x16 bitmap scaled up) with an optional small badge
    // such as "HSK1" in the top-left corner.
    void showHanzi(
        const uint8_t* bitmap,
        uint8_t width,
        uint8_t height,
        const char* badge = ""
    );

    // Title bar plus up to three wrapped paragraphs.
    // Bit N of unifontParagraphs draws paragraph N (0-2) with Unifont
    // Latin letters (use it for hanzi + pinyin). Returns false if some
    // text did not fit on the screen.
    bool showTextPage(
        const char* title,
        const char* line1,
        const char* line2 = "",
        const char* line3 = "",
        uint8_t unifontParagraphs = 0
    );

    static constexpr int16_t TEXT_WIDTH = 120;
};

#endif

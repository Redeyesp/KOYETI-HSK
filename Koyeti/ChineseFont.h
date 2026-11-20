#pragma once

#include <Arduino.h>
#include <U8g2lib.h>

// How ASCII characters are drawn.
//   Small   : U8g2 6x12 font (English meanings, the original look).
//   Unifont : embedded 8x16 Unifont glyphs, so plain letters match the
//             tone-marked pinyin vowels and sit on the hanzi baseline.
enum class LatinStyle : uint8_t
{
    Small,
    Unifont
};

class ChineseFont
{
public:
    static void drawUTF8(
        U8G2& display,
        int16_t x,
        int16_t y,
        const char* text,
        LatinStyle latin = LatinStyle::Small
    );

    // Returns rendered width in pixels.
    static int16_t measureUTF8(
        const char* text,
        LatinStyle latin = LatinStyle::Small
    );

    // Returns the number of UTF-8 bytes that fit inside maxWidth.
    // Always stops on a complete UTF-8 character (or Thai cluster).
    static size_t bytesThatFit(
        const char* text,
        int16_t maxWidth,
        LatinStyle latin = LatinStyle::Small
    );

private:
    static uint32_t decodeUTF8(const char*& text);
};

#include "Display.h"
#include "config.h"
#include "ChineseFont.h"

#include "faces/face_normal.h"
#include "faces/face_half.h"
#include "faces/face_closed.h"
#include "faces/face_happy.h"
#include "faces/face_fire1.h"
#include "faces/face_fire2.h"
#include "faces/face_sleepy1.h"
#include "faces/face_sleepy2.h"
#include "faces/face_sleepy3.h"
#include "faces/face_heart1.h"
#include "faces/face_heart2.h"

#include <Wire.h>
#include <U8g2lib.h>
#include <cstring>

static U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(
    U8G2_R0,
    U8X8_PIN_NONE
);

namespace
{
constexpr int16_t SCREEN_WIDTH = 128;
constexpr int16_t TEXT_X = 4;
constexpr int16_t TEXT_WIDTH = Display::TEXT_WIDTH;
static_assert(TEXT_X * 2 + TEXT_WIDTH == SCREEN_WIDTH, "text area must be centred");
constexpr uint8_t MAX_TEXT_ROWS = 3;
constexpr int16_t ROW_Y[MAX_TEXT_ROWS] = {13, 30, 47};

void drawCenteredXbm(
    const uint8_t* bitmap,
    uint8_t width,
    uint8_t height
)
{
    const int16_t x = (128 - width) / 2;
    const int16_t y = (64 - height) / 2;
    oled.drawXBMP(x, y, width, height, bitmap);
}

// Returns false when the paragraph ran out of rows before it was finished.
bool drawWrappedParagraph(
    const char* text,
    uint8_t& row,
    LatinStyle latin
)
{
    if (text == nullptr || *text == '\0')
    {
        return true;
    }

    const char* cursor = text;

    while (*cursor != '\0' && row < MAX_TEXT_ROWS)
    {
        // Skip spaces at the beginning of a wrapped row.
        while (*cursor == ' ')
        {
            ++cursor;
        }

        if (*cursor == '\0')
        {
            break;
        }

        size_t bytes = ChineseFont::bytesThatFit(
            cursor,
            TEXT_WIDTH,
            latin
        );

        if (bytes == 0)
        {
            break;
        }

        // Prefer wrapping at the last space (English words, pinyin
        // syllables). Hanzi and Thai can wrap at any character boundary.
        size_t split = bytes;

        if (cursor[bytes] != '\0')
        {
            size_t lastSpace = 0;

            for (size_t i = 0; i < bytes; ++i)
            {
                if (cursor[i] == ' ')
                {
                    lastSpace = i;
                }
            }

            if (lastSpace > 0)
            {
                split = lastSpace;
            }
        }

        char buffer[96];

        if (split >= sizeof(buffer))
        {
            split = sizeof(buffer) - 1;
        }

        memcpy(buffer, cursor, split);
        buffer[split] = '\0';

        ChineseFont::drawUTF8(
            oled,
            TEXT_X,
            ROW_Y[row],
            buffer,
            latin
        );

        ++row;
        cursor += split;

        while (*cursor == ' ')
        {
            ++cursor;
        }
    }

    return *cursor == '\0';
}

// Draw one pixel-art Z. The glyph becomes smaller as it rises.
void drawSleepZ(int16_t x, int16_t y, uint8_t phase)
{
    // phase 0 = newly born near the head (largest)
    // phase 7 = highest point (smallest)
    uint8_t w;
    uint8_t h;
    uint8_t thickness;

    if (phase <= 2)
    {
        w = 9; h = 6; thickness = 1;
    }
    else if (phase <= 5)
    {
        w = 7; h = 5; thickness = 1;
    }
    else
    {
        w = 5; h = 4; thickness = 1;
    }

    // Top and bottom bars.
    for (uint8_t t = 0; t < thickness; ++t)
    {
        oled.drawHLine(x, y + t, w);
        oled.drawHLine(x, y + h - 1 - t, w);
    }

    // Diagonal from upper-right to lower-left.
    const int16_t x1 = x + w - 1 - thickness;
    const int16_t y1 = y + thickness;
    const int16_t x2 = x + thickness;
    const int16_t y2 = y + h - 1 - thickness;
    oled.drawLine(x1, y1, x2, y2);
    if (thickness > 1)
    {
        oled.drawLine(x1 - 1, y1, x2 - 1, y2);
    }
}
}

void Display::begin()
{
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);
    oled.begin();

    // Thai vowels and tone marks are drawn over the base consonant.
    // Transparent bitmap mode prevents those overlay glyphs from erasing it.
    oled.setBitmapMode(1);
}

void Display::showBoot()
{
    oled.clearBuffer();
    oled.setFont(u8g2_font_ncenB10_tr);
    oled.drawStr(29, 29, "KOYETI");
    oled.setFont(u8g2_font_6x12_tr);
    oled.drawStr(43, 48, "HSK 1-2");
    oled.sendBuffer();
}

void Display::showFace(Face face)
{
    oled.clearBuffer();

    switch (face)
    {
        case Face::Half:
            drawCenteredXbm(face_half, face_half_width, face_half_height);
            break;

        case Face::Closed:
            drawCenteredXbm(face_closed, face_closed_width, face_closed_height);
            break;

        case Face::Happy:
            drawCenteredXbm(face_happy, face_happy_width, face_happy_height);
            break;

        case Face::Fire1:
            drawCenteredXbm(face_fire1, face_fire1_width, face_fire1_height);
            break;

        case Face::Fire2:
            drawCenteredXbm(face_fire2, face_fire2_width, face_fire2_height);
            break;

        case Face::Sleepy1:
            drawCenteredXbm(face_sleepy1, face_sleepy1_width, face_sleepy1_height);
            break;

        case Face::Sleepy2:
            drawCenteredXbm(face_sleepy2, face_sleepy2_width, face_sleepy2_height);
            break;

        case Face::Sleepy3:
            drawCenteredXbm(face_sleepy3, face_sleepy3_width, face_sleepy3_height);
            break;

        case Face::Heart1:
            drawCenteredXbm(face_heart1, face_heart1_width, face_heart1_height);
            break;

        case Face::Heart2:
            drawCenteredXbm(face_heart2, face_heart2_width, face_heart2_height);
            break;

        case Face::Normal:
        default:
            drawCenteredXbm(face_normal, face_normal_width, face_normal_height);
            break;
    }

    oled.sendBuffer();
}

void Display::showSleepingFrame(uint8_t frame)
{
    // 10-frame sleep cycle:
    // Zs appear one by one, drift upward-right, disappear,
    // then the animation rests before repeating.
    frame %= 10;

    oled.clearBuffer();

    // Static sleeping face; Z particles are drawn separately.
    drawCenteredXbm(face_sleepy3, face_sleepy3_width, face_sleepy3_height);

    // Frames 6-9 are intentionally empty: a quiet sleeping pause.
    if (frame <= 5)
    {
        constexpr int8_t birthFrame[3] = {0, 2, 4};

        for (uint8_t i = 0; i < 3; ++i)
        {
            const int8_t age =
                static_cast<int8_t>(frame) - birthFrame[i];

            // Each Z stays alive for four frames.
            if (age < 0 || age > 3)
            {
                continue;
            }

            // Drift from near the head toward the upper-right.
            const int16_t x = 88 + (age * 6);
            const int16_t y = 24 - (age * 5);

            // Older Zs become smaller.
            const uint8_t visualPhase =
                static_cast<uint8_t>(age * 2);

            drawSleepZ(x, y, visualPhase);
        }
    }

    oled.sendBuffer();
}

void Display::showHanzi(
    const uint8_t* bitmap,
    uint8_t width,
    uint8_t height,
    const char* badge
)
{
    oled.clearBuffer();

    uint8_t scale = HANZI_SCALE;

    while (scale > 1 && (width * scale > 128 || height * scale > 64))
    {
        --scale;
    }

    const uint16_t scaledWidth = width * scale;
    const uint16_t scaledHeight = height * scale;
    const int16_t offsetX = (128 - scaledWidth) / 2;
    const int16_t offsetY = (64 - scaledHeight) / 2;
    const uint8_t bytesPerRow = (width + 7) / 8;

    for (uint8_t y = 0; y < height; ++y)
    {
        for (uint8_t x = 0; x < width; ++x)
        {
            const uint16_t byteIndex = y * bytesPerRow + (x / 8);
            const uint8_t value = pgm_read_byte(bitmap + byteIndex);
            const bool pixelOn = (value & (1U << (x % 8))) != 0;

            if (pixelOn)
            {
                oled.drawBox(
                    offsetX + x * scale,
                    offsetY + y * scale,
                    scale,
                    scale
                );
            }
        }
    }

    if (badge != nullptr && *badge != '\0')
    {
        oled.setFont(u8g2_font_5x8_tr);
        oled.drawStr(1, 8, badge);
    }

    oled.sendBuffer();
}

bool Display::showTextPage(
    const char* title,
    const char* line1,
    const char* line2,
    const char* line3,
    uint8_t unifontParagraphs
)
{
    oled.clearBuffer();

    oled.setFont(u8g2_font_5x8_tr);
    oled.drawStr(2, 8, title);
    oled.drawHLine(0, 11, 128);

    oled.setFont(u8g2_font_6x12_tr);

    const char* paragraphs[MAX_TEXT_ROWS] = {line1, line2, line3};
    uint8_t row = 0;
    bool complete = true;

    // Each paragraph wraps into the next available OLED row.
    for (uint8_t i = 0; i < MAX_TEXT_ROWS; ++i)
    {
        const LatinStyle latin = (unifontParagraphs & (1U << i)) != 0
            ? LatinStyle::Unifont
            : LatinStyle::Small;

        complete = drawWrappedParagraph(paragraphs[i], row, latin) && complete;
    }

    oled.sendBuffer();

    if (!complete)
    {
        // Shows up when a new lesson entry is too long for the 128x64 screen.
        Serial.print("[Display] Text did not fit on page: ");
        Serial.println(title);
    }

    return complete;
}

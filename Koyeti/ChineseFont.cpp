#include "ChineseFont.h"
#include "ChineseFontData.h"

#include <cstring>

namespace
{
constexpr int16_t SCREEN_WIDTH = 128;
constexpr int16_t SMALL_ASCII_ADVANCE = 6;
constexpr int16_t SMALL_ASCII_BASELINE = 12;

bool readGlyphAt(uint16_t index, FontGlyph& glyph)
{
    if (index >= fontGlyphCount)
    {
        return false;
    }

    memcpy_P(
        &glyph,
        &fontGlyphs[index],
        sizeof(FontGlyph)
    );

    return true;
}

bool findGlyph(uint32_t codepoint, FontGlyph& result)
{
    int32_t low = 0;
    int32_t high = static_cast<int32_t>(fontGlyphCount) - 1;

    while (low <= high)
    {
        const int32_t middle = low + ((high - low) / 2);
        FontGlyph glyph;

        if (!readGlyphAt(static_cast<uint16_t>(middle), glyph))
        {
            return false;
        }

        if (glyph.codepoint == codepoint)
        {
            result = glyph;
            return true;
        }

        if (glyph.codepoint < codepoint)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return false;
}

uint32_t decodeUtf8Local(const char*& text)
{
    const uint8_t first = static_cast<uint8_t>(*text);

    if (first == 0)
    {
        return 0;
    }

    if (first < 0x80)
    {
        ++text;
        return first;
    }

    if ((first & 0xE0) == 0xC0)
    {
        const uint8_t second = static_cast<uint8_t>(text[1]);
        if ((second & 0xC0) != 0x80)
        {
            ++text;
            return 0xFFFD;
        }
        text += 2;
        return ((first & 0x1F) << 6) | (second & 0x3F);
    }

    if ((first & 0xF0) == 0xE0)
    {
        const uint8_t second = static_cast<uint8_t>(text[1]);
        const uint8_t third = static_cast<uint8_t>(text[2]);
        if ((second & 0xC0) != 0x80 || (third & 0xC0) != 0x80)
        {
            ++text;
            return 0xFFFD;
        }
        text += 3;
        return ((first & 0x0F) << 12) | ((second & 0x3F) << 6) | (third & 0x3F);
    }

    if ((first & 0xF8) == 0xF0)
    {
        const uint8_t second = static_cast<uint8_t>(text[1]);
        const uint8_t third = static_cast<uint8_t>(text[2]);
        const uint8_t fourth = static_cast<uint8_t>(text[3]);
        if ((second & 0xC0) != 0x80 || (third & 0xC0) != 0x80 || (fourth & 0xC0) != 0x80)
        {
            ++text;
            return 0xFFFD;
        }
        text += 4;
        return ((first & 0x07) << 18) | ((second & 0x3F) << 12) | ((third & 0x3F) << 6) | (fourth & 0x3F);
    }

    ++text;
    return 0xFFFD;
}

bool isThai(uint32_t codepoint)
{
    return codepoint >= 0x0E00 && codepoint <= 0x0E7F;
}

bool isThaiCombiningMark(uint32_t codepoint)
{
    return
        codepoint == 0x0E31
        || (codepoint >= 0x0E34 && codepoint <= 0x0E3A)
        || (codepoint >= 0x0E47 && codepoint <= 0x0E4E);
}

// ASCII drawn from the embedded Unifont glyphs (pinyin rows).
bool unifontAscii(uint32_t codepoint, LatinStyle latin, FontGlyph& glyph)
{
    return codepoint < 0x80
        && latin == LatinStyle::Unifont
        && findGlyph(codepoint, glyph);
}

int16_t glyphAdvance(uint32_t codepoint, LatinStyle latin)
{
    FontGlyph glyph;

    if (codepoint < 0x80)
    {
        return unifontAscii(codepoint, latin, glyph)
            ? glyph.width
            : SMALL_ASCII_ADVANCE;
    }

    if (isThaiCombiningMark(codepoint))
    {
        return 0;
    }

    if (!findGlyph(codepoint, glyph))
    {
        return isThai(codepoint) ? 8 : 12;
    }

    return glyph.width;
}

void drawBitmapGlyph(
    U8G2& display,
    int16_t x,
    int16_t y,
    const FontGlyph& glyph
)
{
    const uint8_t* bitmap = fontBitmapPool + glyph.bitmapOffset;

    display.drawXBMP(
        x + glyph.xOffset,
        y,
        glyph.width,
        glyph.height,
        bitmap
    );
}

// Consume every Thai combining mark that belongs to the base character.
// This makes wrapping operate on a Thai grapheme cluster instead of on
// individual Unicode code points, so vowels/tone marks can never be left
// behind on the previous/next OLED row.
const char* thaiClusterEnd(const char* afterBase)
{
    const char* cursor = afterBase;

    while (*cursor != '\0')
    {
        const char* probe = cursor;
        const uint32_t next = decodeUtf8Local(probe);

        if (!isThaiCombiningMark(next))
        {
            break;
        }

        cursor = probe;
    }

    return cursor;
}
}

uint32_t ChineseFont::decodeUTF8(const char*& text)
{
    return decodeUtf8Local(text);
}

int16_t ChineseFont::measureUTF8(const char* text, LatinStyle latin)
{
    if (text == nullptr)
    {
        return 0;
    }

    int16_t width = 0;

    while (*text != '\0')
    {
        const uint32_t codepoint = decodeUTF8(text);

        if (codepoint == 0)
        {
            break;
        }

        width += glyphAdvance(codepoint, latin);

        if (isThai(codepoint) && !isThaiCombiningMark(codepoint))
        {
            text = thaiClusterEnd(text);
        }
    }

    return width;
}

size_t ChineseFont::bytesThatFit(
    const char* text,
    int16_t maxWidth,
    LatinStyle latin
)
{
    if (text == nullptr || maxWidth <= 0)
    {
        return 0;
    }

    const char* start = text;
    const char* cursor = text;
    int16_t width = 0;

    while (*cursor != '\0')
    {
        const char* before = cursor;
        const char* afterCodepoint = cursor;
        const uint32_t codepoint = decodeUTF8(afterCodepoint);

        if (codepoint == 0)
        {
            break;
        }

        const int16_t advance = glyphAdvance(codepoint, latin);

        // A Thai base + all following marks is one indivisible display cell.
        const char* afterCluster = afterCodepoint;

        if (isThai(codepoint) && !isThaiCombiningMark(codepoint))
        {
            afterCluster = thaiClusterEnd(afterCodepoint);
        }

        if (width + advance > maxWidth)
        {
            break;
        }

        width += advance;
        cursor = afterCluster;

        if (cursor <= before)
        {
            break;
        }
    }

    return static_cast<size_t>(cursor - start);
}

void ChineseFont::drawUTF8(
    U8G2& display,
    int16_t x,
    int16_t y,
    const char* text,
    LatinStyle latin
)
{
    if (text == nullptr)
    {
        return;
    }

    // Thai combining marks must overlay the base glyph without clearing it.
    // U8g2 bitmap mode 1 makes zero bits transparent.
    display.setBitmapMode(1);

    int16_t cursorX = x;

    while (*text != '\0')
    {
        const uint32_t codepoint = decodeUTF8(text);

        if (codepoint == 0)
        {
            break;
        }

        if (codepoint < 0x80)
        {
            FontGlyph glyph;

            if (unifontAscii(codepoint, latin, glyph))
            {
                if (cursorX + glyph.width > SCREEN_WIDTH)
                {
                    break;
                }

                drawBitmapGlyph(display, cursorX, y, glyph);
                cursorX += glyph.width;
                continue;
            }

            if (cursorX + SMALL_ASCII_ADVANCE > SCREEN_WIDTH)
            {
                break;
            }

            char character[2] = {
                static_cast<char>(codepoint),
                '\0'
            };

            display.drawStr(cursorX, y + SMALL_ASCII_BASELINE, character);
            cursorX += SMALL_ASCII_ADVANCE;
            continue;
        }

        // Thai is drawn one grapheme cluster at a time. The consonant/base
        // consumes one 8-pixel cell while upper/lower vowels and tone marks
        // are overlaid inside that SAME cell using their native Unifont
        // vertical positions.
        if (isThai(codepoint) && !isThaiCombiningMark(codepoint))
        {
            FontGlyph baseGlyph;
            const int16_t advance = glyphAdvance(codepoint, latin);

            if (cursorX + advance > SCREEN_WIDTH)
            {
                break;
            }

            if (findGlyph(codepoint, baseGlyph))
            {
                drawBitmapGlyph(display, cursorX, y, baseGlyph);
            }
            else
            {
                display.drawFrame(cursorX, y + 2, 7, 12);
            }

            // Draw all marks belonging to this Thai base at the same X cell.
            while (*text != '\0')
            {
                const char* probe = text;
                const uint32_t markCodepoint = decodeUTF8(probe);

                if (!isThaiCombiningMark(markCodepoint))
                {
                    break;
                }

                FontGlyph markGlyph;

                if (findGlyph(markCodepoint, markGlyph))
                {
                    drawBitmapGlyph(display, cursorX, y, markGlyph);
                }

                text = probe;
            }

            cursorX += advance;
            continue;
        }

        // Orphan Thai combining mark: normally impossible after cluster-safe
        // wrapping, but draw it in the current cell rather than dropping it.
        if (isThaiCombiningMark(codepoint))
        {
            FontGlyph markGlyph;

            if (findGlyph(codepoint, markGlyph))
            {
                drawBitmapGlyph(display, cursorX, y, markGlyph);
            }

            continue;
        }

        FontGlyph glyph;

        if (!findGlyph(codepoint, glyph))
        {
            constexpr int16_t MISSING_ADVANCE = 12;

            if (cursorX + MISSING_ADVANCE > SCREEN_WIDTH)
            {
                break;
            }

            display.drawFrame(cursorX, y + 2, 10, 12);
            cursorX += MISSING_ADVANCE;
            continue;
        }

        if (cursorX + glyph.width > SCREEN_WIDTH)
        {
            break;
        }

        drawBitmapGlyph(display, cursorX, y, glyph);
        cursorX += glyph.width;
    }
}

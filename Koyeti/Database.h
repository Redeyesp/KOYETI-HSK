#ifndef DATABASE_H
#define DATABASE_H

#include <Arduino.h>

// One HSK word that uses the card's character.
struct VocabWord
{
    const char* word;      // hanzi, e.g. "你好"
    const char* pinyin;    // with tone marks, e.g. "nǐ hǎo"
    const char* meaning;   // English (or Thai, see build_all.py --lang)
    uint8_t hsk;           // HSK level of the word
};

struct HanziCard
{
    const uint8_t* bitmap; // 16x16 Unifont bitmap, XBM bit order
    uint8_t width;
    uint8_t height;
    uint8_t hsk;           // first HSK level that uses this character
    const char* pinyin;    // readings, e.g. "jiào / jué"
    const char* meaning;
    const VocabWord* words;
    uint8_t wordCount;
};

class Database
{
public:
    void begin();
    uint16_t count() const;
    uint16_t randomIndex(uint16_t avoidIndex = UINT16_MAX);
    const HanziCard& card(uint16_t index) const;
};

#endif

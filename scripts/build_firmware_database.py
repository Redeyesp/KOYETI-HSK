from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any

from firmware_text import MEANING_LANGUAGE, card_pinyin, meaning_text

ROOT = Path(__file__).resolve().parent.parent
DATABASE = ROOT / "assets" / "database" / "koyeti_database.json"
OUTPUT = ROOT / "Koyeti" / "Database.cpp"


def cpp_string(value: str) -> str:
    """Return a UTF-8-safe C++ string literal."""
    return json.dumps(value, ensure_ascii=False)


def identifier(unicode_hex: str) -> str:
    return f"U{unicode_hex.upper()}"


RUNTIME = r"""
constexpr uint16_t CARD_COUNT =
    sizeof(CARDS) / sizeof(CARDS[0]);

constexpr uint8_t HISTORY_SIZE = 10;
Preferences preferences;
uint16_t recentHistory[HISTORY_SIZE];
uint8_t historyCount = 0;

bool isRecent(uint16_t index)
{
    for (uint8_t i = 0; i < historyCount; ++i)
        if (recentHistory[i] == index) return true;
    return false;
}

void rememberCard(uint16_t index)
{
    if (historyCount < HISTORY_SIZE)
        recentHistory[historyCount++] = index;
    else
    {
        for (uint8_t i = 1; i < HISTORY_SIZE; ++i)
            recentHistory[i - 1] = recentHistory[i];
        recentHistory[HISTORY_SIZE - 1] = index;
    }
    preferences.putUChar("histCount", historyCount);
    preferences.putBytes("history", recentHistory, historyCount * sizeof(uint16_t));
}
}

void Database::begin()
{
    randomSeed(esp_random());
    preferences.begin("koyeti-hsk", false);
    historyCount = preferences.getUChar("histCount", 0);
    if (historyCount > HISTORY_SIZE) historyCount = 0;
    const size_t expected = historyCount * sizeof(uint16_t);
    if (expected > 0 && preferences.getBytesLength("history") == expected)
        preferences.getBytes("history", recentHistory, expected);
    else if (expected > 0)
        historyCount = 0;
    for (uint8_t i = 0; i < historyCount; ++i)
        if (recentHistory[i] >= CARD_COUNT) { historyCount = 0; break; }
}

uint16_t Database::count() const
{
    return CARD_COUNT;
}

uint16_t Database::randomIndex(uint16_t avoidIndex)
{
    if (CARD_COUNT <= 1) return 0;
    uint16_t result;
    uint16_t attempts = 0;
    do
    {
        result = static_cast<uint16_t>(esp_random() % CARD_COUNT);
        ++attempts;
    }
    while ((result == avoidIndex || isRecent(result)) && attempts < 1000);
    if (result == avoidIndex || isRecent(result))
    {
        for (uint16_t i = 0; i < CARD_COUNT; ++i)
        {
            if (i != avoidIndex && !isRecent(i))
            {
                result = i;
                break;
            }
        }
    }
    rememberCard(result);
    return result;
}

const HanziCard& Database::card(uint16_t index) const
{
    return CARDS[index % CARD_COUNT];
}
"""


def build_database_cpp(database: dict[str, Any]) -> str:
    cards = database.get("cards", [])

    if not cards:
        raise ValueError("Database contains no cards.")

    lines: list[str] = [
        "// Generated automatically by scripts/build_firmware_database.py. Do not edit.",
        f"// Meaning language: {MEANING_LANGUAGE}",
        '#include "Database.h"',
        "#include <Preferences.h>",
        "#include <esp_system.h>",
        "",
    ]

    for card in cards:
        unicode_hex = str(card["unicode"]).upper()
        lines.append(f'#include "generated/hanzi/hanzi_{unicode_hex}.h"')

    lines.extend(["", "namespace", "{"])

    for card in cards:
        unicode_hex = str(card["unicode"]).upper()
        name = identifier(unicode_hex)
        vocabulary = card.get("vocabulary", [])

        if not vocabulary:
            continue

        lines.append(f"// {card['character']}")
        lines.append(f"const VocabWord WORDS_{name}[] =")
        lines.append("{")

        for item in vocabulary:
            lines.append(
                "    {"
                f"{cpp_string(item['word'])}, "
                f"{cpp_string(item['pinyin'])}, "
                f"{cpp_string(meaning_text(item.get('meaning')))}, "
                f"{int(item.get('hsk', 0))}"
                "},"
            )

        lines.append("};")
        lines.append("")

    lines.append("const HanziCard CARDS[] =")
    lines.append("{")

    for card in cards:
        unicode_hex = str(card["unicode"]).upper()
        name = identifier(unicode_hex)
        vocabulary = card.get("vocabulary", [])
        words_name = f"WORDS_{name}" if vocabulary else "nullptr"

        lines.extend(
            [
                f"    // {card['character']}",
                "    {",
                f"        hanzi_{unicode_hex},",
                f"        hanzi_{unicode_hex}_width,",
                f"        hanzi_{unicode_hex}_height,",
                f"        {int(card.get('hsk', 0))},",
                f"        {cpp_string(card_pinyin(card))},",
                f"        {cpp_string(meaning_text(card.get('meaning')))},",
                f"        {words_name},",
                f"        {len(vocabulary)},",
                "    },",
            ]
        )

    lines.append("};")
    return "\n".join(lines) + "\n" + RUNTIME


def main() -> int:
    print()
    print("======================================")
    print(" KOYETI FIRMWARE DATABASE BUILDER")
    print("======================================")
    print()

    if not DATABASE.exists():
        print("ERROR : KOYETI database not found.")
        print(DATABASE)
        return 1

    with DATABASE.open("r", encoding="utf-8") as file:
        database = json.load(file)

    try:
        output = build_database_cpp(database)
    except (KeyError, TypeError, ValueError) as error:
        print("ERROR :", error)
        return 1

    OUTPUT.write_text(output, encoding="utf-8")

    print(f"Meaning language : {MEANING_LANGUAGE}")
    print(f"Cards            : {len(database.get('cards', []))}")
    print(OUTPUT)
    print("SUCCESS")

    return 0


if __name__ == "__main__":
    sys.exit(main())

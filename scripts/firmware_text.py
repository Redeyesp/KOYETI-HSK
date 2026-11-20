"""Shared rules for the text that ends up in the firmware.

build_firmware_database.py writes these strings into Database.cpp and
build_font_header.py uses the same list to decide which glyphs to embed,
so the two can never disagree.

Two text styles exist on the OLED:

* SMALL   - ASCII uses the U8g2 6x12 font; anything else (Thai) comes from
            the embedded Unifont glyphs.
* UNIFONT - every character, ASCII included, comes from the embedded Unifont
            glyphs (8x16 Latin, 16x16 hanzi). Used for hanzi and pinyin so
            tone marks line up with the letters around them.
"""

from __future__ import annotations

import os
from typing import Any, Iterator

SMALL = "small"
UNIFONT = "unifont"

# Language shown on the MEANING and WORD pages: "en" or "th".
# build_all.py --lang th sets this through the environment.
DEFAULT_MEANING_LANGUAGE = "en"
MEANING_LANGUAGE = os.environ.get("KOYETI_MEANING_LANG", DEFAULT_MEANING_LANGUAGE)

if MEANING_LANGUAGE not in ("en", "th"):
    raise SystemExit(f"Unsupported meaning language: {MEANING_LANGUAGE!r} (use en or th)")


def join_text(value: Any, separator: str = " / ") -> str:
    if isinstance(value, str):
        return value
    if isinstance(value, list):
        return separator.join(item for item in value if isinstance(item, str) and item)
    return ""


def meaning_text(meaning: Any) -> str:
    # "; " is one character shorter than " / " - it matters on a 20-column row.
    if isinstance(meaning, dict):
        text = join_text(meaning.get(MEANING_LANGUAGE), "; ")
        if text:
            return text
        return join_text(meaning.get("en"), "; ")
    return join_text(meaning, "; ")


def card_pinyin(card: dict[str, Any]) -> str:
    return join_text(card.get("pinyin"))


def firmware_strings(database: dict[str, Any]) -> Iterator[tuple[str, str]]:
    """Yield (text, style) for every string the firmware will draw."""
    for card in database.get("cards", []):
        yield card["character"], UNIFONT
        yield card_pinyin(card), UNIFONT
        yield meaning_text(card.get("meaning")), SMALL
        for word in card.get("vocabulary", []):
            yield word["word"], UNIFONT
            yield " ", UNIFONT
            yield word["pinyin"], UNIFONT
            yield meaning_text(word.get("meaning")), SMALL


def required_codepoints(database: dict[str, Any]) -> list[int]:
    codepoints: set[int] = set()
    for text, style in firmware_strings(database):
        for character in text:
            codepoint = ord(character)
            if style == UNIFONT or codepoint >= 0x80:
                codepoints.add(codepoint)
    return sorted(codepoints)

from __future__ import annotations

import json
import re
import sys
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parent.parent
DATABASE_DIR = ROOT / "assets" / "database"
FONT_CACHE = DATABASE_DIR / "unifont.cache.json"
HANZI_DATABASE = DATABASE_DIR / "hanzi_database.json"

# Letters allowed in pinyin: plain Latin, ü, and the four tone marks on each vowel.
PINYIN_LETTERS = set(
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "āáǎàēéěèīíǐìōóǒòūúǔùüǖǘǚǜĀÁǍÀĒÉĚÈŌÓǑÒ"
    " '-"
)

MAX_WORDS_PER_CARD = 250  # firmware stores the count in a uint8_t

errors = 0
warnings = 0


def error(message: str) -> None:
    global errors
    errors += 1
    print(f"[ERROR] {message}")


def warning(message: str) -> None:
    global warnings
    warnings += 1
    print(f"[WARNING] {message}")


def non_empty_string(value: Any) -> bool:
    return isinstance(value, str) and bool(value.strip())


def non_empty_string_list(value: Any) -> bool:
    return (
        isinstance(value, list)
        and len(value) > 0
        and all(non_empty_string(item) for item in value)
    )


def is_hanzi(character: str) -> bool:
    codepoint = ord(character)
    return (
        0x3400 <= codepoint <= 0x4DBF
        or 0x4E00 <= codepoint <= 0x9FFF
        or 0xF900 <= codepoint <= 0xFAFF
    )


def validate_pinyin(owner: str, value: Any) -> None:
    if not non_empty_string(value):
        error(f"{owner} : pinyin must be a non-empty string")
        return
    bad = sorted({ch for ch in value if ch not in PINYIN_LETTERS})
    if bad:
        error(f"{owner} : pinyin '{value}' contains unsupported characters {bad}")


def validate_meaning(owner: str, value: Any) -> None:
    if not isinstance(value, dict):
        error(f"{owner} : meaning must be an object")
        return

    for language in ("en", "th"):
        meanings = value.get(language)
        if not non_empty_string_list(meanings):
            error(f"{owner} : meaning.{language} must be a non-empty string list")

    english = value.get("en")
    if isinstance(english, list):
        for item in english:
            if isinstance(item, str) and not item.isascii():
                error(
                    f"{owner} : meaning.en '{item}' must be plain ASCII "
                    "(the firmware draws English with the U8g2 6x12 font)"
                )


def main() -> int:

    global errors, warnings
    errors = 0
    warnings = 0

    print()
    print("======================================")
    print("     KOYETI DATABASE VALIDATOR")
    print("======================================")
    print()

    if not FONT_CACHE.exists():
        error("Font cache not found.")
        return 1

    if not HANZI_DATABASE.exists():
        error("Hanzi database not found.")
        return 1

    with FONT_CACHE.open("r", encoding="utf-8") as file:
        glyphs = json.load(file).get("glyphs", {})

    with HANZI_DATABASE.open("r", encoding="utf-8") as file:
        database = json.load(file)

    cards = database.get("cards")

    if not isinstance(cards, list) or not cards:
        error("cards must be a non-empty list")
        return 1

    unicode_set: set[str] = set()
    character_set: set[str] = set()

    print(f"Cards : {len(cards)}")
    print()

    required_fields = (
        "unicode",
        "character",
        "hsk",
        "stroke_count",
        "tags",
        "pinyin",
        "meaning",
        "vocabulary",
        "notes",
    )

    for card_number, card in enumerate(cards, 1):

        if not isinstance(card, dict):
            error(f"Card {card_number} : card must be an object")
            continue

        label = card.get("character", f"Card {card_number}")

        for field in required_fields:
            if field not in card:
                error(f"{label} : missing '{field}'")

        unicode_hex = card.get("unicode")
        character = card.get("character")

        if not isinstance(unicode_hex, str) or not re.fullmatch(r"[0-9A-F]{4,6}", unicode_hex):
            error(f"{label} : unicode must be uppercase hexadecimal (4-6 digits)")
        else:
            if unicode_hex in unicode_set:
                error(f"{label} : duplicated unicode {unicode_hex}")
            unicode_set.add(unicode_hex)

            if isinstance(character, str) and len(character) == 1:
                expected = f"{ord(character):04X}"
                if unicode_hex != expected:
                    error(f"{label} : unicode {unicode_hex} does not match U+{expected}")

            if unicode_hex not in glyphs:
                error(f"{label} : hanzi glyph not found in font cache")

        if not isinstance(character, str) or len(character) != 1:
            error(f"{label} : character must contain exactly one Unicode character")
        else:
            if not is_hanzi(character):
                error(f"{label} : character is not a CJK ideograph")
            if character in character_set:
                error(f"{label} : duplicated character")
            character_set.add(character)

        hsk = card.get("hsk")
        if not isinstance(hsk, int) or not 1 <= hsk <= 9:
            error(f"{label} : hsk must be an integer from 1 to 9")

        stroke_count = card.get("stroke_count")
        if not isinstance(stroke_count, int) or stroke_count <= 0:
            error(f"{label} : stroke_count must be a positive integer")

        tags = card.get("tags")
        if not isinstance(tags, list) or not all(non_empty_string(item) for item in tags):
            error(f"{label} : tags must be a string list")
        elif len(tags) != len(set(tags)):
            error(f"{label} : duplicated tags")

        readings = card.get("pinyin")
        if not non_empty_string_list(readings):
            error(f"{label} : pinyin must be a non-empty string list")
        else:
            for reading in readings:
                validate_pinyin(label, reading)

        validate_meaning(label, card.get("meaning"))

        vocabulary = card.get("vocabulary")

        if not isinstance(vocabulary, list) or not vocabulary:
            error(f"{label} : vocabulary must be a non-empty list")
        elif len(vocabulary) > MAX_WORDS_PER_CARD:
            error(f"{label} : too many vocabulary words ({len(vocabulary)})")
        else:
            seen_words: set[str] = set()

            for index, item in enumerate(vocabulary, 1):
                owner = f"{label} vocabulary {index}"

                if not isinstance(item, dict):
                    error(f"{owner} : item must be an object")
                    continue

                word = item.get("word")

                if not non_empty_string(word):
                    error(f"{owner} : word must be a non-empty string")
                else:
                    if isinstance(character, str) and character not in word:
                        error(f"{owner} : '{word}' does not contain {character}")
                    if word in seen_words:
                        error(f"{owner} : duplicated word {word}")
                    seen_words.add(word)
                    for ch in word:
                        if f"{ord(ch):04X}" not in glyphs:
                            error(f"{owner} : glyph for {ch} not found in font cache")

                validate_pinyin(owner, item.get("pinyin"))

                word_level = item.get("hsk")
                if not isinstance(word_level, int) or not 1 <= word_level <= 9:
                    error(f"{owner} : hsk must be an integer from 1 to 9")

                validate_meaning(owner, item.get("meaning"))

        frequency = card.get("frequency")
        if frequency is not None and (not isinstance(frequency, int) or frequency <= 0):
            error(f"{label} : frequency must be null or a positive integer")

        notes = card.get("notes")
        if not isinstance(notes, str):
            error(f"{label} : notes must be a string")

    print()
    print("--------------------------------------")
    print(f"Errors   : {errors}")
    print(f"Warnings : {warnings}")
    print("--------------------------------------")

    if errors:
        print()
        print("VALIDATION FAILED")
        return 1

    print()
    print("VALIDATION PASSED")
    return 0


if __name__ == "__main__":
    sys.exit(main())

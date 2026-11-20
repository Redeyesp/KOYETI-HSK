from __future__ import annotations

import json
import sys
from pathlib import Path
from typing import Any

from firmware_text import MEANING_LANGUAGE, required_codepoints

ROOT = Path(__file__).resolve().parent.parent
DATABASE_DIR = ROOT / "assets" / "database"
FONT_CACHE = DATABASE_DIR / "unifont.cache.json"
DATABASE = DATABASE_DIR / "koyeti_database.json"
OUTPUT = ROOT / "Koyeti" / "ChineseFontData.h"
LEGACY_OUTPUT = ROOT / "Koyeti" / "JapaneseFontData.h"


def reverse_byte(value: int) -> int:
    value = ((value & 0xF0) >> 4) | ((value & 0x0F) << 4)
    value = ((value & 0xCC) >> 2) | ((value & 0x33) << 2)
    value = ((value & 0xAA) >> 1) | ((value & 0x55) << 1)
    return value


def bitmap_to_xbm_bytes(bitmap_rows: list[str], width: int, height: int) -> list[int]:
    if width <= 0 or height <= 0:
        raise ValueError(f"Invalid glyph dimensions: {width}x{height}")
    if len(bitmap_rows) < height:
        raise ValueError(f"Bitmap has {len(bitmap_rows)} rows; expected {height}")

    bytes_per_row = (width + 7) // 8
    output: list[int] = []

    for row_index in range(height):
        row_value = int(bitmap_rows[row_index], 16)
        for byte_index in range(bytes_per_row):
            shift = (bytes_per_row - 1 - byte_index) * 8
            output.append(reverse_byte((row_value >> shift) & 0xFF))

    return output


def format_bytes(values: list[int]) -> list[str]:
    return [
        "    " + ", ".join(f"0x{value:02X}" for value in values[start:start + 16]) + ","
        for start in range(0, len(values), 16)
    ]


def describe(codepoint: int) -> str:
    character = chr(codepoint)
    if codepoint == 0x20:
        return "space"
    if 0x0E31 <= codepoint <= 0x0E4E:
        return f"◌{character}"  # show Thai marks on a dotted circle
    return character


def build_header(font_cache: dict[str, Any], database: dict[str, Any]) -> tuple[str, int, int]:
    glyph_cache = font_cache.get("glyphs")
    if not isinstance(glyph_cache, dict):
        raise ValueError("Font cache does not contain a valid glyphs object.")

    codepoints = required_codepoints(database)
    if not codepoints:
        raise ValueError("No characters found in the database.")

    glyphs: list[dict[str, Any]] = []
    bitmap_pool: list[int] = []
    missing: list[str] = []

    for codepoint in codepoints:
        unicode_hex = f"{codepoint:04X}"
        source = glyph_cache.get(unicode_hex)
        if source is None:
            missing.append(f"{chr(codepoint)} (U+{unicode_hex})")
            continue

        width = int(source["width"])
        height = int(source["height"])
        bitmap = bitmap_to_xbm_bytes(source["bitmap"], width, height)

        glyphs.append(
            {
                "codepoint": codepoint,
                "unicode_hex": unicode_hex,
                "width": width,
                "height": height,
                "x_offset": int(source.get("x_offset", 0)),
                "y_offset": int(source.get("y_offset", 0)),
                "bitmap_offset": len(bitmap_pool),
            }
        )
        bitmap_pool.extend(bitmap)

    if missing:
        raise ValueError("Missing glyphs:\n" + "\n".join(f"  - {item}" for item in missing))

    lines = [
        "#pragma once",
        "",
        "#include <Arduino.h>",
        "",
        "// Generated automatically by scripts/build_font_header.py. Do not edit.",
        "// Contains exactly the Unifont glyphs the firmware draws: hanzi, pinyin",
        f"// letters and tone marks, and any non-ASCII meaning text ({MEANING_LANGUAGE}).",
        "",
        "struct FontGlyph",
        "{",
        "    uint32_t codepoint;",
        "    uint32_t bitmapOffset;",
        "    uint8_t width;",
        "    uint8_t height;",
        "    int8_t xOffset;",
        "    int8_t yOffset;",
        "};",
        "",
        "const uint8_t fontBitmapPool[] PROGMEM =",
        "{",
    ]
    lines.extend(format_bytes(bitmap_pool))
    lines += ["};", "", "const FontGlyph fontGlyphs[] PROGMEM =", "{"]

    for glyph in glyphs:
        lines += [
            f"    // {describe(glyph['codepoint'])} U+{glyph['unicode_hex']}",
            "    {",
            f"        0x{glyph['unicode_hex']},",
            f"        {glyph['bitmap_offset']},",
            f"        {glyph['width']},",
            f"        {glyph['height']},",
            f"        {glyph['x_offset']},",
            f"        {glyph['y_offset']},",
            "    },",
        ]

    lines += [
        "};",
        "",
        "constexpr uint16_t fontGlyphCount =",
        "    sizeof(fontGlyphs) / sizeof(fontGlyphs[0]);",
        "",
    ]
    return "\n".join(lines), len(glyphs), len(bitmap_pool)


def main() -> int:
    print("\n======================================")
    print(" KOYETI FONT HEADER BUILDER")
    print("======================================\n")

    if not FONT_CACHE.exists():
        print("ERROR : Font cache not found. Run build_cache.py first.")
        return 1
    if not DATABASE.exists():
        print("ERROR : KOYETI database not found.")
        return 1

    with FONT_CACHE.open("r", encoding="utf-8") as file:
        font_cache = json.load(file)
    with DATABASE.open("r", encoding="utf-8") as file:
        database = json.load(file)

    try:
        header, glyph_count, byte_count = build_header(font_cache, database)
    except (KeyError, TypeError, ValueError) as error:
        print("ERROR :", error)
        return 1

    OUTPUT.write_text(header, encoding="utf-8")

    if LEGACY_OUTPUT.exists():
        LEGACY_OUTPUT.unlink()
        print(f"- removed legacy header: {LEGACY_OUTPUT.name}")

    print(f"Meaning language : {MEANING_LANGUAGE}")
    print(f"Glyphs           : {glyph_count}")
    print(f"Bitmap bytes     : {byte_count}")
    print(OUTPUT)
    return 0


if __name__ == "__main__":
    sys.exit(main())

from __future__ import annotations

import json
import sys
from pathlib import Path

# ==========================================================
# Configuration
# ==========================================================

ROOT = Path(__file__).resolve().parent.parent

DATABASE = (
    ROOT
    / "assets"
    / "database"
    / "koyeti_database.json"
)

OUTPUT_DIR = ROOT / "Koyeti" / "generated" / "hanzi"
LEGACY_KANJI_DIR = ROOT / "Koyeti" / "generated" / "kanji"


# ==========================================================
# Reverse Bit Order
# ==========================================================

def reverse_byte(value: int) -> int:

    value = ((value & 0xF0) >> 4) | ((value & 0x0F) << 4)
    value = ((value & 0xCC) >> 2) | ((value & 0x33) << 2)
    value = ((value & 0xAA) >> 1) | ((value & 0x55) << 1)

    return value


def build_header_for_card(card: dict) -> str:

    unicode_hex = card["unicode"]
    width = card["width"]
    height = card["height"]
    bitmap = card["bitmap"]

    lines = []

    lines.append("#pragma once")
    lines.append("")
    lines.append("#include <Arduino.h>")
    lines.append("")
    lines.append(f"constexpr uint8_t hanzi_{unicode_hex}_width = {width};")
    lines.append(f"constexpr uint8_t hanzi_{unicode_hex}_height = {height};")
    lines.append("")
    lines.append(f"const uint8_t hanzi_{unicode_hex}[] PROGMEM =")
    lines.append("{")

    bytes_per_row = width // 8

    for row in bitmap:

        value = int(row, 16)

        row_bytes = []

        for i in range(bytes_per_row):

            shift = (bytes_per_row - 1 - i) * 8

            b = (value >> shift) & 0xFF

            b = reverse_byte(b)

            row_bytes.append(f"0x{b:02X}")

        lines.append("    " + ", ".join(row_bytes) + ",")

    lines.append("};")
    lines.append("")

    return "\n".join(lines)


# ==========================================================
# Main
# ==========================================================

def main():

    print()
    print("======================================")
    print("      KOYETI HEADER BUILDER")
    print("======================================")
    print()

    if not DATABASE.exists():

        print("ERROR : Database not found.")
        print(DATABASE)

        return 1

    with DATABASE.open(
        "r",
        encoding="utf-8",
    ) as file:

        database = json.load(file)

    cards = database["cards"]

    if not cards:

        print("ERROR : Database contains no cards.")

        return 1

    OUTPUT_DIR.mkdir(
        parents=True,
        exist_ok=True,
    )

    # Clean up legacy per-kanji headers from the Arduino sketch root.
    # Keeping hundreds of generated headers beside Koyeti.ino makes the IDE
    # open them as sketch tabs and becomes increasingly slow.
    sketch_dir = ROOT / "Koyeti"
    legacy_headers = list(sketch_dir.glob("kanji_*.h")) + list(sketch_dir.glob("hanzi_*.h"))
    for existing in legacy_headers:
        existing.unlink()
        print(f"- removed legacy sketch header: {existing.name}")

    # Remove the per-kanji headers left over from the Japanese version.
    if LEGACY_KANJI_DIR.exists():
        for existing in LEGACY_KANJI_DIR.glob("*.h"):
            existing.unlink()
        LEGACY_KANJI_DIR.rmdir()
        print(f"- removed legacy folder: {LEGACY_KANJI_DIR.name}")

    expected_files = {f"hanzi_{card['unicode']}.h" for card in cards}

    # Remove stale generated headers from cards that were deleted.
    for existing in OUTPUT_DIR.glob("hanzi_*.h"):
        if existing.name not in expected_files:
            existing.unlink()
            print(f"- removed stale header: {existing.name}")

    for card in cards:

        unicode_hex = card["unicode"]

        output_path = OUTPUT_DIR / f"hanzi_{unicode_hex}.h"

        output_path.write_text(
            build_header_for_card(card),
            encoding="utf-8",
        )

        print(
            f"✓ {card['character']} (U+{unicode_hex}) "
            f"{card['width']}x{card['height']} -> {output_path.name}"
        )

    print()
    print("--------------------------------------")
    print(f"Headers generated : {len(cards)}")
    print(OUTPUT_DIR)
    print("--------------------------------------")
    print()
    print("SUCCESS")

    return 0


if __name__ == "__main__":

    sys.exit(main())
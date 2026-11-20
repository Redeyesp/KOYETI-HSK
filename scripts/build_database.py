from __future__ import annotations

import json
import sys
from pathlib import Path


# ==========================================================
# Paths
# ==========================================================

ROOT = Path(__file__).resolve().parent.parent

DATABASE_DIR = ROOT / "assets" / "database"

FONT_CACHE = DATABASE_DIR / "unifont.cache.json"

HANZI_DATABASE = DATABASE_DIR / "hanzi_database.json"

OUTPUT = DATABASE_DIR / "koyeti_database.json"


# ==========================================================
# Main
# ==========================================================

def main():

    print()
    print("======================================")
    print("      KOYETI DATABASE BUILDER")
    print("======================================")
    print()

    if not FONT_CACHE.exists():
        print("ERROR : Font cache not found.")
        return 1

    if not HANZI_DATABASE.exists():
        print("ERROR : Hanzi database not found.")
        return 1

    # --------------------------------------------------

    print("Loading Font Cache...")

    with FONT_CACHE.open(
        "r",
        encoding="utf-8",
    ) as file:

        font = json.load(file)

    glyphs = font["glyphs"]

    # --------------------------------------------------

    print("Loading Hanzi Database...")

    with HANZI_DATABASE.open(
        "r",
        encoding="utf-8",
    ) as file:

        database = json.load(file)

    metadata = database["metadata"]

    cards = []

    print()
    print("Merging...")
    print()

    # --------------------------------------------------

    for card in database["cards"]:

        unicode_hex = card["unicode"]

        if unicode_hex not in glyphs:

            print(
                f"ERROR : {unicode_hex} not found in font cache."
            )

            return 1

        glyph = glyphs[unicode_hex]

        # Keep every field from the lesson card and add the 16x16 bitmap.
        merged = dict(card)
        merged.update(
            {
                "width": glyph["width"],
                "height": glyph["height"],
                "x_offset": glyph["x_offset"],
                "y_offset": glyph["y_offset"],
                "bitmap": glyph["bitmap"],
            }
        )

        cards.append(merged)

        print(
            f"✓ {card['character']} ({unicode_hex})"
        )

    # --------------------------------------------------

    output = {

        "metadata": metadata,

        "card_count": len(cards),

        "cards": cards,

    }

    with OUTPUT.open(
        "w",
        encoding="utf-8",
    ) as file:

        json.dump(
            output,
            file,
            ensure_ascii=False,
            separators=(",", ":"),
        )

    print()
    print("--------------------------------------")
    print("Database created successfully.")
    print(f"Cards : {len(cards)}")
    print(OUTPUT)
    print("--------------------------------------")

    return 0


if __name__ == "__main__":
    sys.exit(main())
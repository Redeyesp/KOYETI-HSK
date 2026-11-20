from __future__ import annotations

import json
import sys
from datetime import datetime
from pathlib import Path


# ==========================================================
# Configuration
# ==========================================================

PROJECT_ROOT = Path(__file__).resolve().parent.parent

FONT_FILE = (
    PROJECT_ROOT
    / "assets"
    / "fonts"
    / "unifont-15.1.01.bdf"
)

OUTPUT_DIR = (
    PROJECT_ROOT
    / "assets"
    / "database"
)

OUTPUT_FILE = OUTPUT_DIR / "unifont.cache.json"


# ==========================================================
# Parse BDF
# ==========================================================

def parse_bdf(font_file: Path):

    glyphs = {}
    characters = {}

    current_encoding = None
    current_bbx = None
    current_bitmap = []

    inside = False
    reading_bitmap = False

    with font_file.open(
        "r",
        encoding="utf-8",
        errors="replace",
    ) as file:

        for raw in file:

            line = raw.strip()

            # ---------------------------------
            # STARTCHAR
            # ---------------------------------

            if line.startswith("STARTCHAR"):

                inside = True

                current_encoding = None
                current_bbx = None
                current_bitmap = []

                reading_bitmap = False

                continue

            if not inside:
                continue

            # ---------------------------------
            # ENCODING
            # ---------------------------------

            if line.startswith("ENCODING"):

                current_encoding = int(
                    line.split()[1]
                )

                continue

            # ---------------------------------
            # BBX
            # ---------------------------------

            if line.startswith("BBX"):

                current_bbx = list(
                    map(
                        int,
                        line.split()[1:]
                    )
                )

                continue

            # ---------------------------------
            # BITMAP
            # ---------------------------------

            if line == "BITMAP":

                reading_bitmap = True

                current_bitmap = []

                continue

            if reading_bitmap and line != "ENDCHAR":

                current_bitmap.append(
                    line.upper()
                )

                continue

            # ---------------------------------
            # ENDCHAR
            # ---------------------------------

            if line == "ENDCHAR":

                if (
                    current_encoding is not None
                    and current_encoding >= 0
                    and current_bbx
                    and current_bitmap
                ):

                    unicode_hex = (
                        f"{current_encoding:04X}"
                    )

                    character = chr(
                        current_encoding
                    )

                    glyph = {

                        "unicode": unicode_hex,

                        "char": character,

                        "codepoint": current_encoding,

                        "width": current_bbx[0],

                        "height": current_bbx[1],

                        "x_offset": current_bbx[2],

                        "y_offset": current_bbx[3],

                        "bitmap": current_bitmap,

                    }

                    glyphs[unicode_hex] = glyph

                    characters[character] = unicode_hex

                inside = False

                reading_bitmap = False

    return glyphs, characters


# ==========================================================
# Main
# ==========================================================

def main():

    print()
    print("======================================")
    print("     KOYETI FONT CACHE BUILDER")
    print("======================================")
    print()

    if not FONT_FILE.exists():

        print("ERROR : Font file not found")
        print(FONT_FILE)

        return 1

    print("Reading BDF...")
    print()

    glyphs, characters = parse_bdf(FONT_FILE)

    if not glyphs:

        print("No glyph found.")

        return 1

    OUTPUT_DIR.mkdir(
        parents=True,
        exist_ok=True,
    )

    cache = {

        "name": "Koyeti Font Cache",

        "version": "1.0",

        "source_font": FONT_FILE.name,

        "generated": datetime.now().isoformat(),

        "glyph_count": len(glyphs),

        "character_count": len(characters),

        "glyphs": glyphs,

        "characters": characters,

    }

    print(
        f"Glyphs     : {len(glyphs):,}"
    )

    print(
        f"Characters : {len(characters):,}"
    )

    print()

    print("Writing JSON Cache...")

    with OUTPUT_FILE.open(
        "w",
        encoding="utf-8",
    ) as file:

        json.dump(
            cache,
            file,
            ensure_ascii=False,
            separators=(",", ":"),
        )

    print("Done.")
    print()
    print(OUTPUT_FILE)
    print()

    # ---------------------------------
    # Example
    # ---------------------------------

    unicode_hex = characters["汉"]

    glyph = glyphs[unicode_hex]

    print("Example")
    print("-----------------------------")

    print("Character :", glyph["char"])

    print("Unicode   :", glyph["unicode"])

    print("Codepoint :", glyph["codepoint"])

    print(
        f"Size       : {glyph['width']} x {glyph['height']}"
    )

    print()

    for row in glyph["bitmap"]:

        print(row)

    print()

    print("Finished.")

    return 0


if __name__ == "__main__":

    sys.exit(main())
"""Save an enlarged PNG of one character's Unifont bitmap.

Usage: python scripts/preview.py 好   (writes assets/bitmap/preview_597D.png)
"""

import json
import sys
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parent.parent
CACHE = ROOT / "assets/database/unifont.cache.json"
OUTPUT = ROOT / "assets/bitmap"
SCALE = 3


def main():
    character = sys.argv[1] if len(sys.argv) > 1 else "汉"
    unicode_hex = f"{ord(character[0]):04X}"

    with open(CACHE, encoding="utf-8") as f:
        glyph = json.load(f)["glyphs"][unicode_hex]

    w = glyph["width"]
    h = glyph["height"]
    img = Image.new("1", (w * SCALE, h * SCALE), 1)

    for y, row in enumerate(glyph["bitmap"]):
        value = int(row, 16)
        for x in range(w):
            if (value >> (w - 1 - x)) & 1:
                for yy in range(SCALE):
                    for xx in range(SCALE):
                        img.putpixel((x * SCALE + xx, y * SCALE + yy), 0)

    OUTPUT.mkdir(parents=True, exist_ok=True)
    path = OUTPUT / f"preview_{unicode_hex}.png"
    img.save(path)
    print(path)


if __name__ == "__main__":
    main()

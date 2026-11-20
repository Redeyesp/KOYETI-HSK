from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DATABASE = ROOT / "assets" / "database" / "koyeti_database.json"


def find_card(cards, query):
    if len(query) == 1:
        return next((card for card in cards if card["character"] == query), None)
    query = query.upper().removeprefix("U+")
    return next((card for card in cards if card["unicode"] == query), None)


def print_card(card):
    print()
    print("======================================")
    print("HANZI INFORMATION")
    print("======================================")
    print()
    print("Character     :", card["character"])
    print("Unicode       :", card["unicode"])
    print("HSK           :", card["hsk"])
    print("Stroke Count  :", card["stroke_count"])
    print("Pinyin        :", " / ".join(card["pinyin"]))
    print()
    print("Meaning")
    for lang, values in card["meaning"].items():
        print(f"  {lang} : {'; '.join(values)}")
    print()
    print("Vocabulary")
    for word in card["vocabulary"]:
        print()
        print(f"Word     : {word['word']}  (HSK {word['hsk']})")
        print(f"Pinyin   : {word['pinyin']}")
        for lang, values in word["meaning"].items():
            print(f"  {lang} : {'; '.join(values)}")
    print()
    print("Bitmap", f"{card['width']} x {card['height']}")
    print()
    for row in card["bitmap"]:
        bits = bin(int(row, 16))[2:].zfill(card["width"])
        print(bits.replace("0", ".").replace("1", "#"))


def main():
    if len(sys.argv) != 2:
        print()
        print("Usage")
        print()
        print("python scripts/find_hanzi.py 好")
        print("python scripts/find_hanzi.py 597D")
        return 1

    with DATABASE.open("r", encoding="utf-8") as file:
        cards = json.load(file)["cards"]

    card = find_card(cards, sys.argv[1])

    if card is None:
        print()
        print("Hanzi not found.")
        return 1

    print_card(card)
    return 0


if __name__ == "__main__":
    sys.exit(main())

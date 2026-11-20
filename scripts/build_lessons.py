from __future__ import annotations

import json
import sys
from pathlib import Path

# ==========================================================
# Paths
# ==========================================================

ROOT = Path(__file__).resolve().parent.parent

LESSON_DIR = ROOT / "assets" / "database" / "lessons"

OUTPUT = ROOT / "assets" / "database" / "hanzi_database.json"

# ==========================================================
# Main
# ==========================================================


def main():

    print()
    print("======================================")
    print("      KOYETI LESSON BUILDER")
    print("======================================")
    print()

    if not LESSON_DIR.exists():
        print("ERROR : lessons folder not found.")
        print(LESSON_DIR)
        return 1

    # hsk1.json, hsk2.json, ... are merged in file-name order.
    lesson_files = sorted(LESSON_DIR.glob("*.json"))

    if not lesson_files:
        print("ERROR : No lesson files found.")
        return 1

    metadata = None
    cards = []
    seen = set()

    print("Reading lessons...")
    print()

    for lesson in lesson_files:

        print(f"✓ {lesson.name}")

        with lesson.open("r", encoding="utf-8") as f:
            data = json.load(f)

        if metadata is None:
            metadata = dict(data.get("metadata", {}))
            metadata.pop("hsk_level", None)
            metadata.pop("card_count", None)
            metadata.pop("word_count", None)

        for card in data["cards"]:

            character = card["character"]

            if character in seen:
                print(f"WARNING : Duplicate {character} ignored.")
                continue

            seen.add(character)
            cards.append(card)

    output = {
        "metadata": metadata,
        "card_count": len(cards),
        "cards": cards,
    }

    OUTPUT.parent.mkdir(parents=True, exist_ok=True)

    with OUTPUT.open("w", encoding="utf-8") as f:
        json.dump(output, f, ensure_ascii=False, indent=2)

    print()
    print("--------------------------------------")
    print("hanzi_database.json created.")
    print(f"Cards : {len(cards)}")
    print(OUTPUT)
    print("--------------------------------------")

    return 0


if __name__ == "__main__":
    sys.exit(main())

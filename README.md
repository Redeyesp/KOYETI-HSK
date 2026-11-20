# KOYETI — HSK 1–2 Hanzi Companion

KOYETI is an ESP32 Chinese-learning companion using a 128×64 SSD1306 OLED and a touch sensor.
It covers every character in the **HSK 2.0 level 1 and level 2 word lists** (2012 revision):
**347 characters** and **302 words** (150 HSK 1 + 150 HSK 2, plus 但是 and 所以 from the
official pairs 虽然…但是 and 因为…所以).

## Current behavior

- Default screen: animated face.
- Long press: enter or leave review mode.
- Single tap: move through the pages of the current card.
- Double tap: select another random card (the last 10 cards are not repeated).
- Finishing a card plays the celebration animation.
- Double tap on the face still sends a heart to the partner device (ESP-NOW).

Pages for each card:

| Page | Shows |
|------|-------|
| 1 | The character, 48×48, with its HSK level (`HSK1` / `HSK2`) in the corner |
| 2 | `PINYIN` — readings with tone marks, e.g. `jiào / jué` |
| 3 | `MEANING` — meaning of the character on its own |
| 4+ | `WORD n/N  HSKx` — every HSK 1–2 word that uses the character, with pinyin and meaning |

Hanzi use the standard GNU Unifont glyphs, which have Chinese (simplified) character shapes.
Pinyin is drawn with Unifont too, so tone marks (ā á ǎ à, ǖ ǘ ǚ ǜ) line up with the letters.

## Hardware configuration

- OLED SDA: GPIO 8
- OLED SCL: GPIO 9
- Touch sensor: GPIO 7, active HIGH
- Display: SSD1306 128×64 I2C
- Board: ESP32-C3 (`esp32:esp32:esp32c3`)

## Flashing

### Option A — web flasher (Chrome or Edge, nothing to install)

Every push to `main` makes GitHub Actions compile the firmware and publish a flasher page:

**https://redeyesp.github.io/KOYETI-HSK/**

Plug in the ESP32-C3 with a USB data cable, click **Install KOYETI HSK** and pick the port.
If it says "Failed to connect", hold **BOOT** while plugging the cable in, then try again.

One-time repo setting for the page: **Settings → Pages → Source: GitHub Actions**.

The same build is also on the run's **Actions** page as the `KOYETI-HSK-firmware` artifact:

- `KOYETI-HSK-esp32c3.bin` — one file, flash it at address **0x0**
  (e.g. with [Espressif's web flasher](https://espressif.github.io/esptool-js/))
- `bootloader.bin`, `partitions.bin`, `boot_app0.bin`, `koyeti-hsk-app.bin` — separate parts
- `FLASHING.txt` — esptool commands

### Option B — Arduino IDE

Install **esp32 by Espressif Systems** (Boards Manager) and **U8g2 by oliver** (Library
Manager), open `Koyeti/Koyeti.ino`, choose **ESP32C3 Dev Module** and your COM port, then Upload.

## Adding or changing characters

Edit the lesson files:

```text
assets/database/lessons/hsk1.json
assets/database/lessons/hsk2.json
```

Any `*.json` file in `lessons/` is merged in file-name order, so you can add `hsk3.json`
the same way. Then run from the project root:

```bash
python scripts/build_all.py            # English meanings on the device
python scripts/build_all.py --lang th  # Thai meanings on the device
```

The build system automatically:

1. merges the lesson files into `hanzi_database.json`;
2. validates every card (pinyin characters, ASCII-only English, HSK levels, duplicates…);
3. adds each character's 16×16 Unifont bitmap;
4. generates one `generated/hanzi/hanzi_XXXX.h` per card and removes stale ones;
5. creates `ChineseFontData.h` with exactly the glyphs the device will draw
   (hanzi, pinyin letters and tone marks, Thai if `--lang th`);
6. regenerates `Database.cpp` for the firmware.

Generated files should not be edited manually.

## Example card

```json
{
  "unicode": "89C9",
  "character": "觉",
  "hsk": 1,
  "stroke_count": 9,
  "frequency": null,
  "tags": ["hsk1"],
  "pinyin": ["jiào", "jué"],
  "meaning": {
    "en": ["sleep", "to feel"],
    "th": ["การนอน", "รู้สึก"]
  },
  "vocabulary": [
    {
      "word": "睡觉",
      "pinyin": "shuìjiào",
      "hsk": 1,
      "meaning": { "en": ["to sleep"], "th": ["นอนหลับ"] }
    },
    {
      "word": "觉得",
      "pinyin": "juéde",
      "hsk": 2,
      "meaning": { "en": ["to feel", "to think"], "th": ["รู้สึก", "คิดว่า"] }
    }
  ],
  "notes": ""
}
```

Rules worth knowing:

- `meaning.en` must be plain ASCII — the device draws English with the U8g2 6x12 font.
- Pinyin may use letters, ü, tone-marked vowels, spaces, `'` and `-`.
- Each word must contain the card's character.
- If a page has too much text for the screen, the device prints
  `[Display] Text did not fit on page: …` on the serial monitor (115200 baud).

See `assets/database/hanzi_database.schema.json` for the full structure.

## Font

`assets/fonts/unifont-15.1.01.bdf` was converted from GNU Unifont's `unifont.otf` with
`scripts/otf_to_bdf.py` (exact pixel conversion). Unifont is licensed under the SIL Open Font
License 1.1 and GPLv2+ with the GNU Font Embedding Exception.

`build_all.py` skips rebuilding the 57,000-glyph font cache when the BDF has not changed.

# KOYETI Database Workflow (HSK)

The lesson files are the only files that should be edited manually:

```text
assets/database/lessons/hsk1.json
assets/database/lessons/hsk2.json
```

Run:

```bash
python scripts/build_all.py            # English meanings (default)
python scripts/build_all.py --lang th  # Thai meanings
```

The build creates:

- `assets/database/hanzi_database.json` — all lesson cards merged
- `assets/database/koyeti_database.json` — cards plus 16×16 bitmaps
- `Koyeti/generated/hanzi/hanzi_XXXX.h` — one bitmap header per card
- `Koyeti/ChineseFontData.h` — only the glyphs the firmware draws
- `Koyeti/Database.cpp` — the card table compiled into the firmware

Tools:

- `python scripts/find_hanzi.py 好` — print one card and its bitmap
- `python scripts/preview.py 好` — save an enlarged PNG of a glyph
- `python scripts/otf_to_bdf.py <unifont.otf> <out.bdf>` — rebuild the BDF from a newer Unifont

See `assets/database/hanzi_database.schema.json` for the canonical structure.

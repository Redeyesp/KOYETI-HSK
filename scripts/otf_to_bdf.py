"""Convert a GNU Unifont OpenType file into a BDF bitmap font.

GNU Unifont's .otf files are built from square "pixels" (4 font units per
pixel, 64 units per em), so every glyph can be rasterized back to its exact
16-pixel-high bitmap. The output has the same layout as the official Unifont
BDF releases (BBX w 16 0 -2, one hex row per pixel row), so build_cache.py
reads it without changes.

Usage:
    python scripts/otf_to_bdf.py /usr/share/fonts/opentype/unifont/unifont.otf \
        assets/fonts/unifont-15.1.01.bdf

Standard Unifont uses Chinese (Wen Quan Yi) glyph shapes for CJK ideographs,
which is what an HSK learner should see. unifont_jp.otf uses Japanese shapes.
"""

from __future__ import annotations

import sys
from pathlib import Path

from fontTools.pens.basePen import BasePen
from fontTools.ttLib import TTFont

PIXEL = 4          # font units per pixel
ROWS = 16          # Unifont cell height in pixels
DESCENT_PX = 2     # baseline sits 2 pixels above the bottom of the cell


class EdgePen(BasePen):
    """Collects the vertical edges of a rectilinear outline."""

    def __init__(self, glyph_set):
        super().__init__(glyph_set)
        self.edges: list[tuple[float, float, float]] = []  # (x, y0, y1)
        self._start = None
        self._last = None

    def _moveTo(self, point):
        self._start = point
        self._last = point

    def _lineTo(self, point):
        x0, y0 = self._last
        x1, y1 = point
        if x0 != x1 and y0 != y1:
            raise ValueError("non-rectilinear edge")
        if x0 == x1 and y0 != y1:
            self.edges.append((x0, y0, y1))
        self._last = point

    def _curveToOne(self, p1, p2, p3):
        raise ValueError("curve in Unifont outline")

    def _qCurveToOne(self, p1, p2):
        raise ValueError("curve in Unifont outline")

    def _closePath(self):
        if self._last != self._start:
            self._lineTo(self._start)

    def _endPath(self):
        self._closePath()


def rasterize(edges, width_px: int, x_shift_px: int) -> list[int]:
    """Nonzero-winding test at every pixel centre. Returns one int per row."""
    rows: list[int] = []
    for row in range(ROWS):
        # Row 0 is the top of the cell. Font y of this row's pixel centre:
        y = (ROWS - DESCENT_PX - row - 0.5) * PIXEL
        crossings = []
        for x, y0, y1 in edges:
            low, high = (y0, y1) if y0 < y1 else (y1, y0)
            if low < y < high:
                crossings.append((x, 1 if y1 > y0 else -1))
        value = 0
        for col in range(width_px):
            cx = (col - x_shift_px + 0.5) * PIXEL
            winding = sum(direction for ex, direction in crossings if ex < cx)
            if winding != 0:
                value |= 1 << (width_px - 1 - col)
        rows.append(value)
    return rows


def main() -> int:
    if len(sys.argv) != 3:
        print(__doc__)
        return 1

    source = Path(sys.argv[1])
    output = Path(sys.argv[2])

    font = TTFont(source)
    glyph_set = font.getGlyphSet()
    cmap = font.getBestCmap()
    hmtx = font["hmtx"]
    version = font["name"].getDebugName(5) or "unknown"
    family = font["name"].getDebugName(1) or "Unifont"

    records: list[str] = []
    skipped = 0

    for codepoint in sorted(cmap):
        if codepoint > 0xFFFF:
            continue  # BMP only, like the firmware's lookup table
        name = cmap[codepoint]
        advance, _lsb = hmtx[name]
        pen = EdgePen(glyph_set)
        try:
            glyph_set[name].draw(pen)
        except ValueError:
            skipped += 1
            continue

        width_px = advance // PIXEL
        x_shift_px = 0
        if width_px == 0:
            # Combining marks have zero advance and are drawn in the cell to
            # the left of the pen position. Put them back into their own
            # 8- or 16-pixel cell, matching the hex/BDF releases.
            min_x = min((x for x, _y0, _y1 in pen.edges), default=0)
            width_px = 8 if min_x >= -8 * PIXEL else 16
            x_shift_px = width_px
        if width_px not in (8, 16):
            skipped += 1
            continue

        bitmap = rasterize(pen.edges, width_px, x_shift_px)
        digits = width_px // 4
        swidth = 500 if width_px == 8 else 1000
        lines = [
            f"STARTCHAR U+{codepoint:04X}",
            f"ENCODING {codepoint}",
            f"SWIDTH {swidth} 0",
            f"DWIDTH {width_px} 0",
            f"BBX {width_px} 16 0 -2",
            "BITMAP",
        ]
        lines.extend(f"{row:0{digits}X}" for row in bitmap)
        lines.append("ENDCHAR")
        records.append("\n".join(lines))

    header = [
        "STARTFONT 2.1",
        f"FONT -gnu-{family}-Medium-R-Normal-Sans-16-160-75-75-c-80-iso10646-1",
        "SIZE 16 75 75",
        "FONTBOUNDINGBOX 16 16 0 -2",
        f"COMMENT Converted from {source.name} {version} by scripts/otf_to_bdf.py",
        "STARTPROPERTIES 7",
        'COPYRIGHT "GNU Unifont. SIL Open Font License 1.1 and GPLv2+ with the GNU Font Embedding Exception."',
        f'FONT_VERSION "{version}"',
        f'FAMILY_NAME "{family}"',
        "PIXEL_SIZE 16",
        "FONT_ASCENT 14",
        "FONT_DESCENT 2",
        "DEFAULT_CHAR 65533",
        "ENDPROPERTIES",
        f"CHARS {len(records)}",
    ]

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(header) + "\n" + "\n".join(records) + "\nENDFONT\n", encoding="utf-8")
    print(f"{len(records)} glyphs written to {output} ({skipped} skipped)")
    return 0


if __name__ == "__main__":
    sys.exit(main())

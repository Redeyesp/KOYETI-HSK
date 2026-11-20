"""Rebuild every generated file from assets/database/lessons/*.json.

Usage:
    python scripts/build_all.py            # English meanings on the device
    python scripts/build_all.py --lang th  # Thai meanings on the device
"""

from __future__ import annotations

import argparse
import os
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SCRIPTS = ROOT / "scripts"
BDF = ROOT / "assets" / "fonts" / "unifont-15.1.01.bdf"
FONT_CACHE = ROOT / "assets" / "database" / "unifont.cache.json"


def cache_needs_rebuild() -> bool:
    if not FONT_CACHE.exists():
        return True
    if not BDF.exists():
        return False
    return BDF.stat().st_mtime > FONT_CACHE.stat().st_mtime


def build_steps() -> list[tuple[str, str]]:
    steps: list[tuple[str, str]] = []

    if cache_needs_rebuild():
        steps.append(("Build Font Cache", "build_cache.py"))
    else:
        print("Font cache is current; skipping build_cache.py")

    steps.extend(
        [
            ("Build Lessons", "build_lessons.py"),
            ("Validate Database", "validate_database.py"),
            ("Build Database", "build_database.py"),
            ("Build Hanzi Headers", "build_header.py"),
            ("Build Font Header", "build_font_header.py"),
            ("Build Firmware Database", "build_firmware_database.py"),
        ]
    )
    return steps


def run_script(title: str, script: str, env: dict[str, str]) -> None:
    print()
    print("======================================")
    print(title)
    print("======================================")

    script_path = SCRIPTS / script

    if not script_path.exists():
        print(f"ERROR : Script not found: {script_path}")
        sys.exit(1)

    result = subprocess.run(
        [sys.executable, str(script_path)],
        cwd=ROOT,
        env=env,
        check=False,
    )

    if result.returncode != 0:
        print(f"FAILED : {script}")
        sys.exit(result.returncode)

    print("PASS")


def main() -> None:
    parser = argparse.ArgumentParser(description="Build the KOYETI HSK firmware data.")
    parser.add_argument(
        "--lang",
        choices=("en", "th"),
        default="en",
        help="language of the meanings shown on the device (default: en)",
    )
    args = parser.parse_args()

    env = dict(os.environ)
    env["KOYETI_MEANING_LANG"] = args.lang
    env.setdefault("PYTHONIOENCODING", "utf-8")

    print()
    print("======================================")
    print("        KOYETI BUILD SYSTEM")
    print("======================================")
    print(f"Meaning language : {args.lang}")

    for title, script in build_steps():
        run_script(title, script, env)

    print()
    print("======================================")
    print("BUILD COMPLETED SUCCESSFULLY")
    print("======================================")
    print()


if __name__ == "__main__":
    main()

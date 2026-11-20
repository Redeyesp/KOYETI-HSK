#!/usr/bin/env bash
# ============================================================================
#  package_firmware.sh — turn the arduino-cli build into flashable files.
#
#    arduino-cli compile --fqbn esp32:esp32:esp32c3 --output-dir build Koyeti
#    bash scripts/package_firmware.sh
#
#  Needs esptool v5 on PATH (pip install "esptool>=5,<6").
#  Produces:
#    dist/  KOYETI-HSK-esp32c3.bin (one file, flash at 0x0) + separate parts
#    site/  GitHub Pages web flasher (ESP Web Tools page + manifest)
#
#  ESP32-C3 flash layout (default 4 MB partition table):
#    0x0     bootloader     0x8000  partition table
#    0x9000  NVS (review history)   0xE000  otadata (boot_app0)
#    0x10000 application
# ============================================================================
set -euo pipefail
cd "$(dirname "$0")/.."

VERSION="$(sed -n 's/^#define FW_VERSION *"\([^"]*\)".*/\1/p' Koyeti/config.h)"
COMMIT="$(git rev-parse --short HEAD 2>/dev/null || echo local)"
DATE="$(date -u +%Y-%m-%d)"
REPO="${GITHUB_REPOSITORY:-local}"
[ -n "${VERSION}" ] || { echo "ERROR: FW_VERSION not found in Koyeti/config.h" >&2; exit 1; }

for f in Koyeti.ino.bootloader.bin Koyeti.ino.partitions.bin Koyeti.ino.bin; do
  [ -f "build/${f}" ] || { echo "ERROR: missing build/${f} (run arduino-cli compile first)" >&2; ls -la build >&2 || true; exit 1; }
done

BOOT_APP0="$(find "${HOME}/.arduino15/packages/esp32/hardware/esp32" -path '*tools/partitions/boot_app0.bin' 2>/dev/null | sort | tail -n 1 || true)"

rm -rf dist site
mkdir -p dist site/firmware

cp build/Koyeti.ino.bootloader.bin dist/bootloader.bin
cp build/Koyeti.ino.partitions.bin dist/partitions.bin
cp build/Koyeti.ino.bin            dist/koyeti-hsk-app.bin

if [ -n "${BOOT_APP0}" ]; then
  cp "${BOOT_APP0}" dist/boot_app0.bin
  esptool --chip esp32c3 merge-bin -o dist/KOYETI-HSK-esp32c3.bin \
    --flash-mode keep --flash-freq keep --flash-size keep \
    0x0     dist/bootloader.bin \
    0x8000  dist/partitions.bin \
    0xe000  dist/boot_app0.bin \
    0x10000 dist/koyeti-hsk-app.bin
elif [ -f build/Koyeti.ino.merged.bin ]; then
  cp build/Koyeti.ino.merged.bin dist/KOYETI-HSK-esp32c3.bin
else
  echo "ERROR: boot_app0.bin not found and no merged image from the ESP32 core" >&2
  exit 1
fi

cp dist/KOYETI-HSK-esp32c3.bin site/firmware/koyeti-hsk.bin
cat > site/manifest.json <<JSON
{
  "name": "KOYETI HSK 1-2",
  "version": "${VERSION}",
  "new_install_prompt_erase": false,
  "builds": [
    {
      "chipFamily": "ESP32-C3",
      "parts": [
        { "path": "firmware/koyeti-hsk.bin", "offset": 0 }
      ]
    }
  ]
}
JSON

{
  echo "KOYETI HSK 1-2 v${VERSION}  (commit ${COMMIT}, built ${DATE})"
  echo "Board: ESP32-C3, SSD1306 128x64 OLED (SDA 8, SCL 9), touch on GPIO 7"
  echo
  echo "EASIEST: the web flasher on this repo's GitHub Pages site (Chrome/Edge on a PC),"
  echo "or https://espressif.github.io/esptool-js/ with KOYETI-HSK-esp32c3.bin at address 0x0."
  echo
  echo "esptool (replace COM5 with your port):"
  echo "  esptool --chip esp32c3 --port COM5 --baud 460800 write_flash 0x0 KOYETI-HSK-esp32c3.bin"
  echo
  echo "Separate parts (same result):"
  echo "  esptool --chip esp32c3 --port COM5 write_flash 0x0 bootloader.bin 0x8000 partitions.bin 0xe000 boot_app0.bin 0x10000 koyeti-hsk-app.bin"
  echo
  echo "If it doesn't connect: hold BOOT while plugging in the USB cable, then try again."
  echo "After flashing, press RESET (or unplug and replug)."
} > dist/FLASHING.txt

sed -e "s|@VERSION@|${VERSION}|g" -e "s|@COMMIT@|${COMMIT}|g" \
    -e "s|@DATE@|${DATE}|g" -e "s|@REPO@|${REPO}|g" \
    flasher/index.html > site/index.html
cp site/firmware/koyeti-hsk.bin site/KOYETI-HSK-esp32c3.bin
if [ -f docs/ui_preview.png ]; then cp docs/ui_preview.png site/; fi

echo "Packaged KOYETI HSK v${VERSION} (${COMMIT})"
ls -l dist site site/firmware

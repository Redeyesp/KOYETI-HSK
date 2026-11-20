ESP-NOW Heart broadcast-v2
- No router / no Internet / no MQTT.
- Both devices pinned to channel 1.
- Broadcast transport, but receive side accepts only the configured partner MAC.
- Each heart is transmitted 3 times, 80 ms apart.
- Duplicate sequence numbers are ignored.
- Serial Monitor: 115200 baud.
Expected on double tap:
  [PartnerLink] Heart queued #N x3
  [PartnerLink] TX heart #N copy 1/3 -> queued OK
On the other device:
  [PartnerLink] RX HEART #N from ... <3
  [PartnerLink] Showing partner heart <3

# Quote/0 Firmware Resources

This folder contains the public hardware-facing files needed to bring up custom Quote/0 firmware.

## Contents

| Folder | Purpose |
| --- | --- |
| `gpio/` | ESP32-C3 pin usage table in human-readable and machine-readable formats |
| `display/` | UC8251D e-paper driver, display constants, waveform/LUT notes, and initialization guidance |

## Firmware Assumptions

- MCU: ESP32-C3
- Console: USB-Serial-JTAG
- Display bus: SPI using MOSI and CLK, with no MISO line
- Display power is controlled by a dedicated GPIO
- Display framebuffer format is 1 bit per pixel, where `1` means white and `0` means black

These files are intended as reference material. Verify the exact hardware revision before using them in production firmware.


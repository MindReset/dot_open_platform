# Quote/0 Hardware Overview

This overview summarizes the public hardware-facing details currently available for Quote/0.

## MCU

Quote/0 uses an ESP32-C3 MCU.

The default console uses USB-Serial-JTAG, so the public pinout does not reserve extra UART pins for console output.

## Power-Related Signals

| GPIO | Function | Notes |
| --- | --- | --- |
| GPIO0 | VBUS detect | High level means USB or external power is present |
| GPIO1 | Battery voltage sample | ADC input through an internal 50% / 50% resistor divider |
| GPIO20 | E-paper VIN | Controls display power |

## Display Interface

The e-paper display uses an SPI write path:

| Signal | GPIO |
| --- | ---: |
| BUSY | 3 |
| RESET | 4 |
| DC | 5 |
| CS | 6 |
| MOSI | 7 |
| CLK | 10 |
| VIN | 20 |

MISO is not used.

## Display Panel

| Item | Value |
| --- | --- |
| Controller | UC8251D |
| Resolution | 152 x 296 |
| Colors | White and black |
| Pixel format | 1bpp |
| Buffer size | 5,624 bytes |

## Enclosure

The current mechanical release includes a STEP AP242 file exported in millimeter units:

```text
enclosure/step/quote_0-enclosure.step
```

## Current Public Scope

This package currently publishes the resources needed for:

- Enclosure inspection and derivative mechanical work.
- GPIO mapping.
- Display initialization and full-frame refresh.
- Minimal ESP-IDF firmware bring-up.

It does not currently publish PCB source files, schematic PDFs, native CAD files, STL exports, manufacturing drawings, or complete product firmware.


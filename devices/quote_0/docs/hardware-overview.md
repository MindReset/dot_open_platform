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
| Standard edition controller path | UC8251D |
| Early Bird Edition controller path | UC8151/IL0324 |
| Resolution | 152 x 296 |
| Colors | White and black |
| Pixel format | 1bpp |
| Buffer size | 5,624 bytes |

The visible display parameters are the same across the standard edition and Early Bird Edition, but their controller firmware and waveform data differ. Use the Early Bird Edition driver only when the Dot. App device details show `首发版`, `Early Bird Edition`, or `先発版です`.

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

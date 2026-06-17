# Display Integration Guide

This guide documents the display behavior exposed in the public Quote/0 package.

## Controller and Panel

Quote/0 uses a UC8251D-controlled monochrome e-paper display.

| Item | Value |
| --- | --- |
| Width | 152 pixels |
| Height | 296 pixels |
| Buffer size | 5,624 bytes |
| Color depth | 1 bit per pixel |
| White pixel | `1` |
| Black pixel | `0` |

## SPI Signals

| Signal | GPIO | Direction |
| --- | ---: | --- |
| BUSY | 3 | Input |
| RESET | 4 | Output |
| DC | 5 | Output |
| CS | 6 | Output |
| MOSI | 7 | Output |
| CLK | 10 | Output |
| VIN | 20 | Output |

MISO is not used.

## Refresh Flow

The minimal driver follows this flow:

1. Enable display power.
2. Reset the panel.
3. Wait until BUSY is ready.
4. Configure panel and power settings.
5. Load the full-refresh LUT.
6. Write the old frame plane.
7. Write the new frame plane.
8. Trigger display update.
9. Wait until BUSY is ready.
10. Enter sleep when requested.

## Waveform/LUT Data

The public full-refresh LUT is stored in `uc8251d_minimal.c` as `s_lut_gc`.

See:

```text
firmware-resources/display/waveforms/README.md
```

Use this waveform only with the matching controller and panel configuration unless you have validated another display.

## Common Bring-Up Problems

| Symptom | Things to check |
| --- | --- |
| Display never updates | VIN pin, RESET pin, CS pin, SPI host, MOSI/CLK wiring |
| Firmware times out waiting for BUSY | BUSY pin number, pull-up configuration, panel power |
| Image is inverted | Pixel convention: `1 = white`, `0 = black` |
| Image is shifted or corrupted | Buffer size, row packing, SPI mode, transfer length |
| Display works once and then stops | Sleep path, power control, reset before next update |

## Porting Checklist

- Confirm UC8251D controller.
- Confirm 152 x 296 resolution.
- Confirm 1bpp framebuffer size.
- Confirm GPIO mapping.
- Confirm SPI mode 0.
- Confirm display power control behavior.
- Confirm BUSY polarity on the actual panel.


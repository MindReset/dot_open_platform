# Display Integration Guide

This guide documents the display behavior exposed in the public Quote/0 package.

## Controller and Panel

Quote/0 uses a monochrome e-paper display with two driver variants. The standard edition uses the UC8251D driver path. The Early Bird Edition uses the UC8151/IL0324 driver path.

| Item | Value |
| --- | --- |
| Width | 152 pixels |
| Height | 296 pixels |
| Buffer size | 5,624 bytes |
| Color depth | 1 bit per pixel |
| White pixel | `1` |
| Black pixel | `0` |

## Driver Selection

Use the Early Bird Edition driver only when the Dot. App device details show one of these labels:

| Dot. App locale | Device name | Edition label | Driver |
| --- | --- | --- | --- |
| `zh-Hans-CN` | `摘录/0` | `首发版` | `uc8151_minimal.*` |
| `en-US` | `Quote/0` | `Early Bird Edition` | `uc8151_minimal.*` |
| `ja-JP` | `Quote/0` | `先発版です` | `uc8151_minimal.*` |

If the device details do not show one of these labels, use the standard edition driver:

```text
uc8251d_minimal.*
```

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

The minimal drivers follow this flow:

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

The public full-refresh LUT data is stored in the matching driver source file:

- Standard edition: `uc8251d_minimal.c`
- Early Bird Edition: `uc8151_minimal.c`

See:

```text
firmware-resources/display/waveforms/README.md
```

Use each waveform only with the matching controller and panel configuration unless you have validated another display.

## Common Bring-Up Problems

| Symptom | Things to check |
| --- | --- |
| Display never updates | VIN pin, RESET pin, CS pin, SPI host, MOSI/CLK wiring |
| Firmware times out waiting for BUSY | BUSY pin number, pull-up configuration, panel power |
| Image is inverted | Pixel convention: `1 = white`, `0 = black` |
| Image is shifted or corrupted | Buffer size, row packing, SPI mode, transfer length |
| Display works once and then stops | Sleep path, power control, reset before next update |

## Porting Checklist

- Confirm the display variant from Dot. App device details.
- Use `uc8251d_minimal.*` for standard edition devices.
- Use `uc8151_minimal.*` for Early Bird Edition devices.
- Confirm 152 x 296 resolution.
- Confirm 1bpp framebuffer size.
- Confirm GPIO mapping.
- Confirm SPI mode 0.
- Confirm display power control behavior.
- Confirm BUSY polarity on the actual panel.

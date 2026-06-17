# Custom Firmware Guide

This guide explains how to use the public Quote/0 resources when writing your own firmware.

## Recommended Bring-Up Order

1. Confirm the hardware revision you are targeting.
2. Review `firmware-resources/gpio/pinout.md`.
3. Review `firmware-resources/display/driver-selection.md`.
4. Bring up USB-Serial-JTAG logs.
5. Configure display power, reset, DC, CS, MOSI, CLK, and BUSY pins.
6. Initialize SPI.
7. Reset the selected panel and wait for BUSY.
8. Load the matching waveform/LUT.
9. Write a white test frame.
10. Write a visible black/white test pattern.
11. Put the display into sleep after refresh.

## Choose the Display Driver

Quote/0 has two display driver variants:

| Edition shown in Dot. App device details | Driver |
| --- | --- |
| No Early Bird Edition label | `uc8251d_minimal.*` |
| `首发版` / `Early Bird Edition` / `先発版です` | `uc8151_minimal.*` |

The GPIO mapping and framebuffer shape are the same, but the initialization sequence and waveform data are different.

## Default Quote/0 Display Configuration

```c
static const uc8251d_config_t display_config = {
    .spi_host = SPI2_HOST,
    .pin_vin = 20,
    .pin_busy = 3,
    .pin_reset = 4,
    .pin_dc = 5,
    .pin_cs = 6,
    .pin_sck = 10,
    .pin_mosi = 7,
    .spi_clock_hz = 15 * 1000 * 1000,
};
```

## Framebuffer Format

The display buffer is exactly:

```text
152 * 296 / 8 = 5624 bytes
```

Each bit maps to one pixel:

- `1` means white
- `0` means black

The minimal driver sends one full frame at a time. It does not include image parsing or layout rendering.

## Battery and Power

`GPIO1` samples battery voltage through a 50% / 50% resistor divider. Account for that divider in firmware before displaying or reporting battery voltage.

`GPIO20` controls display power. Keep it enabled while resetting, writing data, and refreshing the e-paper panel. The minimal drivers release the pin in their matching sleep functions.

## Porting to Other Frameworks

If you are not using ESP-IDF, port these parts:

- GPIO output set direction and level.
- GPIO input read for BUSY.
- SPI write byte and bulk transfer.
- Millisecond delay.
- Timeout handling for BUSY polling.

The command sequence and LUT loading logic must match the display variant. Use `uc8251d_minimal.*` for standard edition devices and `uc8151_minimal.*` for Early Bird Edition devices.

## What the Minimal Driver Does Not Do

- No Wi-Fi or Bluetooth setup.
- No power manager.
- No file system integration.
- No image decoder.
- No partial refresh.
- No multi-display abstraction.
- No application UI.

This keeps the public driver small enough to inspect and port.

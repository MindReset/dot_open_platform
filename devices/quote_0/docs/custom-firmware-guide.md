# Custom Firmware Guide

This guide explains how to use the public Quote/0 resources when writing your own firmware.

## Recommended Bring-Up Order

1. Confirm the hardware revision you are targeting.
2. Review `firmware-resources/gpio/pinout.md`.
3. Bring up USB-Serial-JTAG logs.
4. Configure display power, reset, DC, CS, MOSI, CLK, and BUSY pins.
5. Initialize SPI.
6. Reset the UC8251D panel and wait for BUSY.
7. Load the included waveform/LUT.
8. Write a white test frame.
9. Write a visible black/white test pattern.
10. Put the display into sleep after refresh.

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

`GPIO20` controls display power. Keep it enabled while resetting, writing data, and refreshing the e-paper panel. The minimal driver releases the pin in `uc8251d_sleep()`.

## Porting to Other Frameworks

If you are not using ESP-IDF, port these parts:

- GPIO output set direction and level.
- GPIO input read for BUSY.
- SPI write byte and bulk transfer.
- Millisecond delay.
- Timeout handling for BUSY polling.

The UC8251D command sequence and LUT loading logic can remain structurally the same, but validate it on your panel and hardware revision.

## What the Minimal Driver Does Not Do

- No Wi-Fi or Bluetooth setup.
- No power manager.
- No file system integration.
- No image decoder.
- No partial refresh.
- No multi-display abstraction.
- No application UI.

This keeps the public driver small enough to inspect and port.


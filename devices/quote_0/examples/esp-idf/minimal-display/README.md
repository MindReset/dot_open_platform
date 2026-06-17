# Quote/0 ESP-IDF Minimal Display Example

This example shows how to initialize the Quote/0 UC8251D display, write a simple 1bpp pattern, refresh the screen, and enter sleep.

## Requirements

- ESP-IDF installed and configured.
- Quote/0 hardware or compatible wiring.
- UC8251D display with the Quote/0 152 x 296 monochrome panel configuration.

## Files

| File | Purpose |
| --- | --- |
| `CMakeLists.txt` | ESP-IDF project file |
| `main/CMakeLists.txt` | Main component definition |
| `main/quote_0_minimal_display_example.c` | Example application |

The example builds against the public driver in:

```text
../../../firmware-resources/display/drivers/
```

## Usage

From this folder, use the normal ESP-IDF flow:

```sh
idf.py set-target esp32c3
idf.py build
idf.py flash monitor
```

## Expected Behavior

The firmware clears the screen to white, draws a small black border pattern into a framebuffer, refreshes the display, and enters display sleep.

## Notes

- The example does not configure Wi-Fi, Bluetooth LE, storage, or application UI.
- If your hardware wiring differs from Quote/0, update `display_config` in the example source file.
- If the display does not refresh, check power, reset, BUSY, CS, MOSI, CLK, and the SPI host.


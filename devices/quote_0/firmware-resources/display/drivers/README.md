# Quote/0 Minimal Display Drivers

This folder contains minimal ESP-IDF display drivers for Quote/0.

Quote/0 uses two display driver variants. The screen size and framebuffer format are the same, but the controller firmware and waveform data differ.

## Which Driver to Use

Use the standard driver unless the Dot. App device details show an Early Bird Edition label.

| Dot. App locale | Device name | Edition label | Driver |
| --- | --- | --- | --- |
| `zh-Hans-CN` | `摘录/0` | `首发版` | `uc8151_minimal.*` |
| `en-US` | `Quote/0` | `Early Bird Edition` | `uc8151_minimal.*` |
| `ja-JP` | `Quote/0` | `先発版です` | `uc8151_minimal.*` |

If the device details do not show one of the edition labels above, use the standard driver:

```text
uc8251d_minimal.*
```

## Files

| File | Purpose |
| --- | --- |
| `uc8251d_minimal.h` | Standard edition public interface, dimensions, buffer size, and GPIO configuration structure |
| `uc8251d_minimal.c` | Standard edition UC8251D SPI/GPIO implementation, initialization sequence, full-refresh waveform/LUT, clear, display, and sleep functions |
| `uc8151_minimal.h` | Early Bird Edition public interface, dimensions, buffer size, and GPIO configuration structure |
| `uc8151_minimal.c` | Early Bird Edition UC8151/IL0324 SPI/GPIO implementation, initialization sequence, full-refresh waveform/LUT, clear, display, and sleep functions |

## Standard Edition API

```c
esp_err_t uc8251d_init(const uc8251d_config_t *config);
esp_err_t uc8251d_display(const uint8_t *data);
esp_err_t uc8251d_clear(bool white);
esp_err_t uc8251d_sleep(void);
```

## Early Bird Edition API

```c
esp_err_t uc8151_init(const uc8151_config_t *config);
esp_err_t uc8151_display(const uint8_t *data);
esp_err_t uc8151_clear(bool white);
esp_err_t uc8151_sleep(void);
```

## Framebuffer Format

- Width: `152`
- Height: `296`
- Buffer size: `5624` bytes
- Pixel format: 1 bit per pixel
- Pixel value: `1 = white`, `0 = black`

## Porting Notes

- Change the selected config type if your GPIO wiring differs from Quote/0.
- Keep MISO disabled unless your hardware adds a display read path.
- Keep the display power pin high while resetting, writing, and refreshing the panel.
- Call the matching sleep function after refresh if your firmware needs low-power behavior.

## License

The driver source code is licensed under Apache-2.0.

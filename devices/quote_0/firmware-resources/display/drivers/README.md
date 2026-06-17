# UC8251D Minimal Driver

This folder contains a minimal ESP-IDF driver for the UC8251D e-paper controller used by Quote/0.

## Files

| File | Purpose |
| --- | --- |
| `uc8251d_minimal.h` | Public interface, dimensions, buffer size, and GPIO configuration structure |
| `uc8251d_minimal.c` | SPI/GPIO implementation, initialization sequence, full-refresh waveform/LUT, clear, display, and sleep functions |

## Public API

```c
esp_err_t uc8251d_init(const uc8251d_config_t *config);
esp_err_t uc8251d_display(const uint8_t *data);
esp_err_t uc8251d_clear(bool white);
esp_err_t uc8251d_sleep(void);
```

## Framebuffer Format

- Width: `152`
- Height: `296`
- Buffer size: `5624` bytes
- Pixel format: 1 bit per pixel
- Pixel value: `1 = white`, `0 = black`

## Porting Notes

- Change `uc8251d_config_t` if your GPIO wiring differs from Quote/0.
- Keep MISO disabled unless your hardware adds a display read path.
- Keep the display power pin high while resetting, writing, and refreshing the panel.
- Call `uc8251d_sleep()` after refresh if your firmware needs low-power behavior.

## License

The driver source code is licensed under Apache-2.0.


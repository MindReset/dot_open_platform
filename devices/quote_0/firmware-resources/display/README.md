# Quote/0 Display Resources

Quote/0 uses a 152 x 296 monochrome e-paper display. There are two display driver variants: the standard edition uses the UC8251D driver, while the Early Bird Edition uses the UC8151/IL0324 driver.

Before porting firmware, read [driver-selection.md](driver-selection.md) and choose the driver that matches the edition shown in the Dot. App device details.

## Display Summary

| Item | Value |
| --- | --- |
| Controller | UC8251D for standard edition; UC8151/IL0324 for Early Bird Edition |
| Resolution | 152 x 296 |
| Color mode | Black and white |
| Pixel format | 1 bit per pixel |
| Pixel value | `1 = white`, `0 = black` |
| Framebuffer size | 5,624 bytes |
| Bus | SPI |
| MISO | Not used |

## Files

| Path | Purpose |
| --- | --- |
| `driver-selection.md` | Rules for choosing the standard or Early Bird Edition display driver |
| `drivers/uc8251d_minimal.h` | Standard edition public interface and display configuration structure |
| `drivers/uc8251d_minimal.c` | Standard edition ESP-IDF implementation for UC8251D full-frame refresh |
| `drivers/uc8151_minimal.h` | Early Bird Edition public interface and display configuration structure |
| `drivers/uc8151_minimal.c` | Early Bird Edition ESP-IDF implementation for UC8151/IL0324 full-frame refresh |
| `waveforms/README.md` | Notes on the included full-refresh waveform/LUT data |
| `init-sequences/README.md` | Initialization sequence notes |

## Standard Edition Minimal Usage

Use this path unless the Dot. App device details show the Early Bird Edition label.

```c
#include <string.h>
#include "uc8251d_minimal.h"

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

void app_main(void)
{
    uc8251d_init(&display_config);
    uc8251d_clear(true);

    uint8_t frame[UC8251D_BUFFER_SIZE];
    memset(frame, 0xFF, sizeof(frame));

    uc8251d_display(frame);
    uc8251d_sleep();
}
```

## Early Bird Edition Minimal Usage

Use this path only when the Dot. App device details show `首发版`, `Early Bird Edition`, or `先発版です`.

```c
#include <string.h>
#include "uc8151_minimal.h"

static const uc8151_config_t display_config = {
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

void app_main(void)
{
    uc8151_init(&display_config);
    uc8151_clear(true);

    uint8_t frame[UC8151_BUFFER_SIZE];
    memset(frame, 0xFF, sizeof(frame));

    uc8151_display(frame);
    uc8151_sleep();
}
```

## Scope

The minimal drivers only cover the public bring-up paths needed by Quote/0:

- SPI bus setup.
- Panel reset and busy polling.
- Full-frame 1bpp refresh.
- White or black clear.
- Display sleep and power control.

It does not include automatic display detection, multi-panel abstraction, image decoding, partial refresh, UI rendering, or application logic.

## License

Driver source files are licensed under Apache-2.0. Display hardware notes and waveform documentation are licensed under CERN-OHL-P-2.0 or CC BY 4.0 according to the repository license policy.

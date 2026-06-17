# Quote/0 Display Driver Selection

Quote/0 has two display driver variants. The screen parameters are the same, but the controller firmware and waveform data are different.

Use the wrong display driver only after you have verified the panel yourself. For normal users and firmware ports, choose the driver based on the Dot. App device details.

## Selection Rule

Use the Early Bird Edition driver only when the Dot. App device details show one of these edition labels:

| Dot. App locale | Device name | Edition label | Driver files |
| --- | --- | --- | --- |
| `zh-Hans-CN` | `摘录/0` | `首发版` | `drivers/uc8151_minimal.h`, `drivers/uc8151_minimal.c` |
| `en-US` | `Quote/0` | `Early Bird Edition` | `drivers/uc8151_minimal.h`, `drivers/uc8151_minimal.c` |
| `ja-JP` | `Quote/0` | `先発版です` | `drivers/uc8151_minimal.h`, `drivers/uc8151_minimal.c` |

If the device details do not show one of the labels above, use the standard edition driver:

```text
drivers/uc8251d_minimal.h
drivers/uc8251d_minimal.c
```

## Variant Summary

| Variant | App label | Controller path | Driver files |
| --- | --- | --- | --- |
| Standard edition | No Early Bird Edition label | UC8251D | `uc8251d_minimal.h`, `uc8251d_minimal.c` |
| Early Bird Edition | `首发版` / `Early Bird Edition` / `先発版です` | UC8151/IL0324 | `uc8151_minimal.h`, `uc8151_minimal.c` |

## Shared Display Parameters

Both variants use the same public framebuffer shape:

| Item | Value |
| --- | --- |
| Resolution | 152 x 296 |
| Color mode | Black and white |
| Pixel format | 1 bit per pixel |
| Pixel value | `1 = white`, `0 = black` |
| Framebuffer size | 5,624 bytes |
| Bus | SPI |
| MISO | Not used |

## Why There Are Two Drivers

The two Quote/0 editions use panels with the same visible screen parameters, but their controller firmware and waveform requirements are different. The driver source therefore keeps separate initialization and LUT paths for the standard edition and the Early Bird Edition.


# UC8251D Initialization Sequence Notes

The public initialization sequence is implemented in:

```text
../drivers/uc8251d_minimal.c
```

The main bring-up flow is:

1. Configure display GPIOs.
2. Enable display power through `GPIO20`.
3. Initialize the SPI bus with MOSI and CLK only.
4. Reset the panel.
5. Wait for BUSY to become ready.
6. Configure panel settings, power settings, booster soft start, resolution, PLL, TCON, VCOM, and border behavior.
7. Power on the panel and wait for BUSY.
8. Load the full-refresh LUT.
9. Write old and new image planes.
10. Trigger display refresh.
11. Enter sleep when the update is complete.

## Quote/0 Default Pins

| Signal | GPIO |
| --- | ---: |
| VIN | 20 |
| BUSY | 3 |
| RESET | 4 |
| DC | 5 |
| CS | 6 |
| MOSI | 7 |
| CLK | 10 |

## Notes

- The driver polls BUSY with command `0x71`.
- The default SPI clock is 15 MHz when `spi_clock_hz` is not provided.
- The display sleep path sends command `0x07` followed by `0xA5`, then releases the display power control pin.


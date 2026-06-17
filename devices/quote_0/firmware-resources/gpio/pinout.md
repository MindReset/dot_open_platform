# Quote/0 GPIO Pinout

This document lists the ESP32-C3 GPIOs used by the current Quote/0 hardware design. Use it for firmware bring-up, hardware migration, and debugging.

## Used GPIOs

| GPIO | Function | Direction | Notes |
| --- | --- | --- | --- |
| GPIO0 | VBUS detect | Input | Detects whether USB or external power is connected. High level means external power is present. |
| GPIO1 | Battery voltage sample | Input / ADC | Reads battery voltage through an internal 50% / 50% resistor divider. |
| GPIO3 | E-paper BUSY | Input | Reads the display busy state. |
| GPIO4 | E-paper RESET | Output | Controls display reset. |
| GPIO5 | E-paper DC | Output | Selects command or data for SPI transfers. |
| GPIO6 | E-paper CS | Output | Display SPI chip select. |
| GPIO7 | E-paper MOSI | Output | Display SPI data output. |
| GPIO10 | E-paper CLK | Output | Display SPI clock. |
| GPIO20 | E-paper VIN | Output | Controls display power. |

## Notes

- The e-paper display uses SPI and does not use MISO.
- The default console uses USB-Serial-JTAG and does not require extra UART pins.
- Wi-Fi, Bluetooth LE, and the internal temperature sensor do not require external GPIOs.

## Machine-Readable Files

- `pinout.csv`
- `pinout.json`

## License

Hardware connection information is licensed under CERN-OHL-P-2.0. This documentation is licensed under CC BY 4.0.


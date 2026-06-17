# File Index

This index lists the public Quote/0 package files and their intended purpose.

## Device Package

| File | Purpose |
| --- | --- |
| `README.md` | Human-readable Quote/0 landing page |
| `manifest.json` | Machine-readable device and asset inventory |

## Enclosure

| File | Purpose |
| --- | --- |
| `enclosure/README.md` | Mechanical resource overview |
| `enclosure/step/quote_0-enclosure.step` | STEP enclosure model |

## Firmware Resources

| File | Purpose |
| --- | --- |
| `firmware-resources/README.md` | Firmware resource overview |
| `firmware-resources/gpio/pinout.md` | Human-readable GPIO table |
| `firmware-resources/gpio/pinout.csv` | CSV GPIO table |
| `firmware-resources/gpio/pinout.json` | JSON GPIO table |
| `firmware-resources/display/README.md` | Display resource overview |
| `firmware-resources/display/driver-selection.md` | Standard vs Early Bird Edition display driver selection |
| `firmware-resources/display/drivers/README.md` | Display driver notes |
| `firmware-resources/display/drivers/uc8251d_minimal.h` | Standard edition public driver header |
| `firmware-resources/display/drivers/uc8251d_minimal.c` | Standard edition minimal driver implementation |
| `firmware-resources/display/drivers/uc8151_minimal.h` | Early Bird Edition public driver header |
| `firmware-resources/display/drivers/uc8151_minimal.c` | Early Bird Edition minimal driver implementation |
| `firmware-resources/display/waveforms/README.md` | Waveform/LUT notes |
| `firmware-resources/display/init-sequences/README.md` | Initialization sequence notes |

## Examples

| File | Purpose |
| --- | --- |
| `examples/esp-idf/minimal-display/README.md` | ESP-IDF example guide |
| `examples/esp-idf/minimal-display/CMakeLists.txt` | ESP-IDF project CMake file |
| `examples/esp-idf/minimal-display/main/CMakeLists.txt` | ESP-IDF main component CMake file |
| `examples/esp-idf/minimal-display/main/quote_0_minimal_display_example.c` | Minimal display refresh example |

## Guides

| File | Purpose |
| --- | --- |
| `docs/getting-started.md` | First steps through the package |
| `docs/hardware-overview.md` | Public hardware summary |
| `docs/custom-firmware-guide.md` | Custom firmware bring-up guide |
| `docs/display-integration.md` | Display behavior and porting guide |
| `docs/enclosure-printing.md` | Mechanical and printing notes |
| `docs/faq.md` | Common questions |
| `docs/file-index.md` | This file |

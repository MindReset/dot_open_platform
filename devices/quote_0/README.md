# Quote/0

Quote/0 is a smart e-ink Dot device published by MindReset. It is designed for calm, glanceable information in everyday spaces and can display app-configured content such as RSS feeds, to-dos, calendars, weather, and custom API-driven updates.

This open device package collects the public files needed to inspect the enclosure, understand the hardware pin map, and build custom firmware that drives the e-paper display.

## Package Contents

| Area | Path | Contents |
| --- | --- | --- |
| Device metadata | `manifest.json` | Machine-readable device and asset index |
| Enclosure | `enclosure/` | Main STEP model, AdventureX 2026 badge STL files, and mechanical documentation |
| GPIO | `firmware-resources/gpio/` | ESP32-C3 pinout in Markdown, CSV, and JSON |
| Display | `firmware-resources/display/` | Standard and Early Bird Edition display drivers, waveform/LUT notes, and integration docs |
| Guides | `docs/` | Getting started, hardware overview, custom firmware, display integration, enclosure notes, FAQ |
| Examples | `examples/` | Minimal ESP-IDF display example |

## Hardware Summary

| Item | Value |
| --- | --- |
| Main MCU | ESP32-C3 |
| Display controller | UC8251D for standard edition; UC8151/IL0324 for Early Bird Edition |
| Display resolution | 152 x 296 |
| Display colors | 1-bit monochrome, white/black |
| Display buffer size | 5,624 bytes |
| Display bus | SPI, MOSI-only, no MISO |
| Console | USB-Serial-JTAG |
| Enclosure files | STEP AP242 exchange file and binary STL meshes |

## Official Online Resources

| Resource | Link |
| --- | --- |
| Developer Platform | https://dot.mindreset.tech/developers |
| Quote/0 product docs | https://dot.mindreset.tech/docs/quote_0 |
| Developer Platform docs | https://dot.mindreset.tech/docs/service/open |
| Text API | https://dot.mindreset.tech/docs/service/open/text_api |
| Image API | https://dot.mindreset.tech/docs/service/open/image_api |
| Canvas API | https://dot.mindreset.tech/docs/service/open/canvas_api |
| Skills | https://dot.mindreset.tech/docs/service/open/skill |
| Content Studio | https://dot.mindreset.tech/docs/service/studio |
| Community Co-Creation | https://dot.mindreset.tech/docs/service/co_create |
| Software Co-Creation | https://dot.mindreset.tech/docs/service/co_create/software |
| Hardware Co-Creation | https://dot.mindreset.tech/docs/service/co_create/hardware |

## Quick Start

1. Review the [getting started guide](docs/getting-started.md).
2. Check the [GPIO pinout](firmware-resources/gpio/pinout.md).
3. Read the [display resources](firmware-resources/display/README.md).
4. Try the [ESP-IDF minimal display example](examples/esp-idf/minimal-display/README.md).
5. Review the [enclosure resources](enclosure/README.md) and inspect the applicable STEP or STL files in your CAD or slicing tool.

## Firmware Bring-Up Path

For a custom firmware port, start with the files in this order:

1. `firmware-resources/gpio/pinout.md`
2. `firmware-resources/display/driver-selection.md`
3. `firmware-resources/display/README.md`
4. Standard edition: `firmware-resources/display/drivers/uc8251d_minimal.h` and `firmware-resources/display/drivers/uc8251d_minimal.c`
5. Early Bird Edition: `firmware-resources/display/drivers/uc8151_minimal.h` and `firmware-resources/display/drivers/uc8151_minimal.c`
6. `examples/esp-idf/minimal-display/`

The minimal display drivers are intentionally small. They focus on initializing the selected panel, sending a full-frame 1bpp buffer, clearing the panel, and entering sleep.

## Custom Firmware Safety

MindReset cannot guarantee the security of custom firmware flashed to Quote/0, and flashing custom firmware voids the device warranty. Before building firmware, read the [custom firmware guide](docs/custom-firmware-guide.md), especially the ESP-IDF console configuration, deep-sleep recovery, and power-on sequence notes.

Use Pure USB Serial/JTAG for ESP-IDF console output. The default UART console pins may conflict with `GPIO20`, which controls display power.

## Mechanical Files

The package includes the main Quote/0 STEP enclosure model and a two-part AdventureX 2026 badge enclosure:

```text
enclosure/step/quote_0-enclosure.step
enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-front.stl
enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-back-cover.stl
```

The STEP file supports inspection, derivative mechanical work, and manufacturing preparation. The AdventureX 2026 binary STL files provide a printable front shell and back cover. Always verify units, tolerances, wall thicknesses, mounting features, and material behavior before production.

## Platform Metadata

Platforms that need a stable inventory should read:

```text
devices/quote_0/manifest.json
```

The manifest lists the device name, hardware summary, resource paths, license scopes, and files included in the current public package.

## Licensing

- Software source code: Apache-2.0
- Hardware design material: CERN-OHL-P-2.0
- Documentation and media: CC BY 4.0

See the repository [license](../../LICENSE.md) and [notice](../../NOTICE.md) for details.

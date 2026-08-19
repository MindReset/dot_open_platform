# Dot Open Platform

Dot Open Platform is the public resource repository for MindReset open devices and device capabilities. It provides mechanical files, firmware bring-up resources, pin maps, display integration notes, local device protocols, examples, and machine-readable metadata for platforms that present or index Dot device materials.

The first device package in this repository is Quote/0.

The repository also includes capability packages for device-local integrations that do not require custom firmware or the Dot cloud platform.

## Available Devices

| Device | Package | Included resources |
| --- | --- | --- |
| Quote/0 | `devices/quote_0/` | Enclosure STEP and AdventureX 2026 badge STL files, ESP32-C3 GPIO map, standard and Early Bird Edition display drivers, display waveform/LUT notes, ESP-IDF example, developer documentation |

## Available Capabilities

| Capability | Package | Included resources |
| --- | --- | --- |
| Rand/0 Display Mode | `capabilities/rand_0_display_mode/` | Local WebSocket protocol reference and an official browser image-sending example |

## Quick Links

- [Quote/0 device package](devices/quote_0/README.md)
- [Quote/0 manifest](devices/quote_0/manifest.json)
- [Quote/0 enclosure resources](devices/quote_0/enclosure/README.md)
- [Quote/0 enclosure STEP](devices/quote_0/enclosure/step/quote_0-enclosure.step)
- [AdventureX 2026 badge front STL](devices/quote_0/enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-front.stl)
- [AdventureX 2026 badge back cover STL](devices/quote_0/enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-back-cover.stl)
- [Quote/0 GPIO pinout](devices/quote_0/firmware-resources/gpio/pinout.md)
- [Display resources](devices/quote_0/firmware-resources/display/README.md)
- [Display driver selection](devices/quote_0/firmware-resources/display/driver-selection.md)
- [Custom firmware guide](devices/quote_0/docs/custom-firmware-guide.md)
- [Rand/0 Display Mode capability](capabilities/rand_0_display_mode/README.md)
- [Rand/0 browser example](capabilities/rand_0_display_mode/examples/web/display_ws_test.html)
- [Repository license](LICENSE.md)
- [Authors](AUTHORS)
- [Maintainers](MAINTAINERS)

## Official Online Resources

For a product-level overview of the Dot developer ecosystem, visit the [Dot Developer Platform](https://dot.mindreset.tech/developers).

The links below point to reference documentation and community resources that are most relevant when using this repository:

| Resource | What it helps you do |
| --- | --- |
| [Quote/0 Docs](https://dot.mindreset.tech/docs/quote_0) | Learn how Quote/0 works, including setup, firmware, and user-facing device behavior. |
| [Developer Platform Docs](https://dot.mindreset.tech/docs/service/open) | Create API keys, find device IDs, read device status, update device settings, and control device content. |
| [Text API](https://dot.mindreset.tech/docs/service/open/text_api) | Send text content to Dot devices. |
| [Image API](https://dot.mindreset.tech/docs/service/open/image_api) | Send image content to Dot devices. |
| [Canvas API](https://dot.mindreset.tech/docs/service/open/canvas_api) | Create structured visual content for Dot devices. |
| [Skills](https://dot.mindreset.tech/docs/service/open/skill) | Build reusable device content workflows. |
| [Content Studio](https://dot.mindreset.tech/docs/service/studio) | Create and manage rich Dot content without writing a full firmware stack. |
| [Community Co-Creation](https://dot.mindreset.tech/docs/service/co_create) | Browse community-built Dot integrations and examples. |
| [Software Co-Creation](https://dot.mindreset.tech/docs/service/co_create/software) | Explore API clients, automations, MCP integrations, dashboards, and software workflows. |
| [Hardware Co-Creation](https://dot.mindreset.tech/docs/service/co_create/hardware) | Explore community mounts, stands, cases, and other hardware accessories. |

## Repository Layout

```text
devices/
  quote_0/
    README.md
    manifest.json
    enclosure/
    firmware-resources/
    docs/
    examples/
capabilities/
  rand_0_display_mode/
    README.md
    protocol.md
    examples/
```

Each device package is intended to be useful in two ways:

1. People can read the documentation directly on GitHub or another public platform.
2. Tools can read `manifest.json` to locate downloadable files and device metadata.

## What Is Included for Quote/0

- A STEP enclosure model exported in millimeter units.
- A two-part AdventureX 2026 badge enclosure provided as binary STL meshes.
- GPIO documentation for the ESP32-C3 pins used by the current Quote/0 hardware design.
- Minimal ESP-IDF display drivers for the 152 x 296 monochrome e-paper display.
- Documentation for selecting the standard or Early Bird Edition display driver.
- Documentation for the included full-refresh waveform/LUT data.
- A minimal ESP-IDF example showing how to initialize and refresh the display.
- Licensing, attribution, contribution, support, and security documentation.

## What Is Included for Rand/0 Display Mode

- A protocol reference for the Rand/0 `200 × 200` local display endpoints.
- An official dependency-free browser example for sending black-and-white or four-level grayscale images.
- Button event handling and local-network security guidance.

## Using These Materials

Start with the [Quote/0 getting started guide](devices/quote_0/docs/getting-started.md). If you are building custom firmware, continue with the [custom firmware guide](devices/quote_0/docs/custom-firmware-guide.md) and the [display integration guide](devices/quote_0/docs/display-integration.md).

If you are working on the enclosure, start with the [enclosure README](devices/quote_0/enclosure/README.md) and inspect the applicable STEP or STL files in your CAD or slicing tool before manufacturing or printing.

If you are building a local Rand/0 display tool, start with the [Rand/0 Display Mode capability](capabilities/rand_0_display_mode/README.md) and its [protocol reference](capabilities/rand_0_display_mode/protocol.md).

## License Summary

This repository uses multiple licenses:

- Software source code: Apache-2.0
- Hardware design material: CERN-OHL-P-2.0
- Documentation and media: CC BY 4.0

See [LICENSE.md](LICENSE.md) and [NOTICE.md](NOTICE.md) before redistributing modified material.

## No Warranty

These resources are provided as open hardware reference material. Verify electrical limits, enclosure tolerances, battery handling, and display behavior before using the files in a production or safety-sensitive context.

MindReset cannot guarantee the security of custom firmware flashed to devices. Flashing custom firmware voids the device warranty. Device-specific safety notes are documented in each custom firmware guide, starting with the [Quote/0 custom firmware guide](devices/quote_0/docs/custom-firmware-guide.md).

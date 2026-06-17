# Dot Open Platform

Dot Open Platform is the public hardware resource repository for MindReset open devices. It provides mechanical files, firmware bring-up resources, pin maps, display integration notes, and machine-readable metadata for platforms that present or index Dot device materials.

The first device package in this repository is Quote/0.

## Available Devices

| Device | Package | Included resources |
| --- | --- | --- |
| Quote/0 | `devices/quote_0/` | Enclosure STEP, ESP32-C3 GPIO map, UC8251D display driver, display waveform/LUT notes, ESP-IDF example, developer documentation |

## Quick Links

- [Quote/0 device package](devices/quote_0/README.md)
- [Quote/0 manifest](devices/quote_0/manifest.json)
- [Quote/0 enclosure STEP](devices/quote_0/enclosure/step/quote_0-enclosure.step)
- [Quote/0 GPIO pinout](devices/quote_0/firmware-resources/gpio/pinout.md)
- [UC8251D display resources](devices/quote_0/firmware-resources/display/README.md)
- [Custom firmware guide](devices/quote_0/docs/custom-firmware-guide.md)
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
```

Each device package is intended to be useful in two ways:

1. People can read the documentation directly on GitHub or another public platform.
2. Tools can read `manifest.json` to locate downloadable files and device metadata.

## What Is Included for Quote/0

- A STEP enclosure model exported in millimeter units.
- GPIO documentation for the ESP32-C3 pins used by the current Quote/0 hardware design.
- A minimal ESP-IDF UC8251D driver for the 152 x 296 monochrome e-paper display.
- Documentation for the included UC8251D full-refresh waveform/LUT data.
- A minimal ESP-IDF example showing how to initialize and refresh the display.
- Licensing, attribution, contribution, support, and security documentation.

## Using These Materials

Start with the [Quote/0 getting started guide](devices/quote_0/docs/getting-started.md). If you are building custom firmware, continue with the [custom firmware guide](devices/quote_0/docs/custom-firmware-guide.md) and the [display integration guide](devices/quote_0/docs/display-integration.md).

If you are working on the enclosure, start with the [enclosure README](devices/quote_0/enclosure/README.md) and inspect the STEP file in your CAD tool before manufacturing or printing.

## License Summary

This repository uses multiple licenses:

- Software source code: Apache-2.0
- Hardware design material: CERN-OHL-P-2.0
- Documentation and media: CC BY 4.0

See [LICENSE.md](LICENSE.md) and [NOTICE.md](NOTICE.md) before redistributing modified material.

## No Warranty

These resources are provided as open hardware reference material. Verify electrical limits, enclosure tolerances, battery handling, and display behavior before using the files in a production or safety-sensitive context.

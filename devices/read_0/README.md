# Read Pico

Read Pico is an ESP32-S3 development board with a 4.7-inch e-paper display, native 16-level grayscale, two-point touch, three touch keys, microSD storage, and USB-C. The product belongs to the Read series.

## Official firmware and hardware references

**[Open the official demo firmware repository](https://github.com/MindReset/read_pico_firmware)**

The firmware repository contains the factory demo, board support, chip drivers, pin assignments, display waveforms, and ESP-IDF build instructions. Its demos cover display refresh, touch, acceleration, power, storage, fonts, and sleep/wake behavior.

This Open Platform package includes the enclosure model and links to firmware resources. Firmware, drivers, and firmware assets are maintained in the dedicated repository and are not duplicated here.

| Resource | Link |
| --- | --- |
| Enclosure model and mechanical notes | [Enclosure resources](enclosure/README.md) |
| Enclosure STEP download | [read_0-enclosure.step](enclosure/step/read_0-enclosure.step) |
| Official firmware, board support, and pinout | [read_pico_firmware](https://github.com/MindReset/read_pico_firmware) |
| Product documentation | [Read Pico](https://dot.mindreset.tech/docs/read_0) |
| Official demo guide | [Getting started](https://dot.mindreset.tech/docs/read_0/start) |
| Build and flash | [Firmware guide](https://dot.mindreset.tech/docs/read_0/firmware) |
| Machine-readable resource index | [manifest.json](manifest.json) |

The firmware currently requires ESP-IDF v6.1 and targets ESP32-S3. Follow its README for board-specific timing and VCOM handling. Firmware and bundled components follow the licenses in that repository; this entry does not relicense those resources.

## Enclosure and Accessories

Use the [enclosure STEP model](enclosure/step/read_0-enclosure.step) to design custom cases, mounts, and accessories. The model uses millimeter units and is provided in STEP AP242 format.

Read the [enclosure notes](enclosure/README.md) before modifying or manufacturing parts. The enclosure is licensed under CERN-OHL-P-2.0; documentation follows CC BY 4.0.

# Read Pico

Read Pico is an ESP32-S3 development board with a 4.7-inch e-paper display, native 16-level grayscale, two-point touch, three touch keys, microSD storage, and USB-C. The product belongs to the Read series.

## Official firmware and hardware references

**[Open the official demo firmware repository](https://github.com/MindReset/read_pico_firmware)**

The firmware repository contains the factory demo, board support, chip drivers, pin assignments, display waveforms, and ESP-IDF build instructions. Its demos cover display refresh, touch, acceleration, power, storage, fonts, and sleep/wake behavior.

This Open Platform package is an entry point. Firmware, drivers, and assets are maintained in the dedicated repository and are not duplicated here.

| Resource | Link |
| --- | --- |
| Official firmware, board support, and pinout | [read_pico_firmware](https://github.com/MindReset/read_pico_firmware) |
| Product documentation | [Read Pico](https://dot.mindreset.tech/docs/read_0) |
| Official demo guide | [Getting started](https://dot.mindreset.tech/docs/read_0/start) |
| Build and flash | [Firmware guide](https://dot.mindreset.tech/docs/read_0/firmware) |
| Machine-readable resource index | [manifest.json](manifest.json) |

The firmware currently requires ESP-IDF v6.1 and targets ESP32-S3. Follow its README for board-specific timing and VCOM handling. Firmware and bundled components follow the licenses in that repository; this entry does not relicense those resources.

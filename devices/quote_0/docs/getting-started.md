# Getting Started with Quote/0

This guide gives you the shortest path through the public Quote/0 resource package.

## 1. Inspect the Device Package

Start with:

- `devices/quote_0/README.md`
- `devices/quote_0/manifest.json`

The README is the human-readable landing page. The manifest is intended for platforms, catalogs, and tooling.

## 2. Review the Official Online Context

Use these pages when you want to connect the hardware package to Dot software capabilities:

| Resource | Link |
| --- | --- |
| Developer Platform | https://dot.mindreset.tech/developers |
| Quote/0 product docs | https://dot.mindreset.tech/docs/quote_0 |
| Developer Platform docs | https://dot.mindreset.tech/docs/service/open |
| Content Studio | https://dot.mindreset.tech/docs/service/studio |
| Community Co-Creation | https://dot.mindreset.tech/docs/service/co_create |
| Software Co-Creation | https://dot.mindreset.tech/docs/service/co_create/software |
| Hardware Co-Creation | https://dot.mindreset.tech/docs/service/co_create/hardware |

## 3. Review the Pinout

Read:

- `firmware-resources/gpio/pinout.md`
- `firmware-resources/gpio/pinout.csv`
- `firmware-resources/gpio/pinout.json`

Use the Markdown file for development. Use CSV or JSON for scripts, documentation generators, or platform import.

## 4. Bring Up the Display

Read:

- `firmware-resources/display/README.md`
- `firmware-resources/display/driver-selection.md`
- `firmware-resources/display/drivers/README.md`
- `firmware-resources/display/waveforms/README.md`

Quote/0 has two display driver variants. Use the Early Bird Edition driver only when the Dot. App device details show `首发版`, `Early Bird Edition`, or `先発版です`. Otherwise, use the standard edition driver.

Both drivers target ESP-IDF and the Quote/0 152 x 296 monochrome panel configuration.

## 5. Try the Example

Open:

```text
examples/esp-idf/minimal-display/
```

The example shows a small full-screen refresh path using the standard edition public driver. For Early Bird Edition devices, use the same GPIO mapping and framebuffer format, but switch to the UC8151/IL0324 driver described in `firmware-resources/display/driver-selection.md`.

## 6. Inspect the Enclosure

Open the STEP file in your CAD tool:

```text
enclosure/step/quote_0-enclosure.step
```

Verify dimensions and tolerances before manufacturing, printing, or modifying the enclosure.

## Safety Notes

- MindReset cannot guarantee the security of custom firmware flashed to devices. Flashing custom firmware voids the device warranty.
- For ESP-IDF custom firmware, use Pure USB Serial/JTAG console output. The default UART console pins may conflict with `GPIO20`; disable `ESP_CONSOLE_UART_DEFAULT` and enable `ESP_CONSOLE_USB_SERIAL_JTAG`.
- Quote/0 does not have a physical reset button. Do not enter deep sleep without a wake timer or external wake trigger.
- If a firmware build leaves the device in deep sleep, disconnect the lithium battery connector (`SH1.0`), connect USB Type-C power, flash corrected firmware, then reconnect the battery.
- When powering on after battery disconnection, connect USB Type-C first and then connect the lithium battery. Repeating that sequence can recover from the battery self-protection state.
- Do not assume battery, charging, thermal, or power behavior from GPIO documentation alone.
- Verify the hardware revision before using these files in production firmware.
- Treat e-paper waveform data as display-specific.
- Do not publish private credentials or supplier-confidential material in examples or issues.

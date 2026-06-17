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
- `firmware-resources/display/drivers/README.md`
- `firmware-resources/display/waveforms/README.md`

The included driver targets ESP-IDF and the UC8251D 152 x 296 monochrome panel configuration used by Quote/0.

## 5. Try the Example

Open:

```text
examples/esp-idf/minimal-display/
```

The example shows a small full-screen refresh path using the public driver.

## 6. Inspect the Enclosure

Open the STEP file in your CAD tool:

```text
enclosure/step/quote_0-enclosure.step
```

Verify dimensions and tolerances before manufacturing, printing, or modifying the enclosure.

## Safety Notes

- Do not assume battery, charging, thermal, or power behavior from GPIO documentation alone.
- Verify the hardware revision before using these files in production firmware.
- Treat e-paper waveform data as display-specific.
- Do not publish private credentials or supplier-confidential material in examples or issues.

# Contributing

Thanks for improving Dot Open Platform resources. Contributions should make the public hardware package easier to inspect, build, port, or manufacture.

## What fits this repository

- Corrections to Quote/0 GPIO, display, enclosure, or firmware integration documentation.
- Small, portable firmware examples that help users bring up the device.
- Small, portable capability examples that help users build local device integrations.
- Mechanical notes, drawings, or enclosure export improvements.
- Clear bug reports with hardware revision, firmware environment, and reproduction steps.

For maintainer responsibilities and ownership, see `MAINTAINERS`. For authorship and attribution, see `AUTHORS` and `NOTICE.md`.

## Before opening a pull request

1. Keep all public documentation in English.
2. Use stable, lowercase file names with hyphens where practical.
3. Add SPDX license identifiers to source files.
4. Put generated or exchange CAD files in the matching enclosure folder.
5. Do not include private keys, Wi-Fi credentials, manufacturing secrets, or supplier-confidential files.
6. Do not add display waveforms, datasheets, or vendor files unless they are cleared for redistribution.

## File locations

- Device landing page: `devices/quote_0/README.md`
- Machine-readable inventory: `devices/quote_0/manifest.json`
- Enclosure files: `devices/quote_0/enclosure/`
- GPIO and firmware resources: `devices/quote_0/firmware-resources/`
- User and developer guides: `devices/quote_0/docs/`
- Examples: `devices/quote_0/examples/`
- Device capabilities: `capabilities/`

## Pull request checklist

- The change has a clear device and file scope.
- Documentation links still point to existing files.
- License scope is clear for any new file.
- Binary CAD or media files have a useful source note in a nearby README.

# Quote/0 Enclosure

This folder contains public mechanical resources for the Quote/0 enclosure.

## Included Files

| File | Format | Notes |
| --- | --- | --- |
| `step/quote_0-enclosure.step` | STEP AP242 | Main Quote/0 enclosure, exported from Shapr3D in millimeter units |
| `stl/adventurex-2026/quote_0-adventurex-2026-badge-front.stl` | Binary STL | AdventureX 2026 badge enclosure front shell |
| `stl/adventurex-2026/quote_0-adventurex-2026-badge-back-cover.stl` | Binary STL | AdventureX 2026 badge enclosure back cover |

The STEP header identifies MindReset and Quote/0, includes the source URL and license identifier, and preserves the export timestamp `2026-06-12T22:04:06+08:00`.

## Folder Layout

| Folder | Purpose |
| --- | --- |
| `step/` | STEP exchange files |
| `stl/adventurex-2026/` | Printable meshes for the AdventureX 2026 badge enclosure |

## AdventureX 2026 Badge Enclosure

The AdventureX 2026 badge enclosure is an alternate two-part Quote/0 shell created for the AdventureX 2026 hackathon. Use the front shell and back cover together.

Design credit: [AdventureX 2026](https://adventure-x.org/en). Published by MindReset.

Each binary STL header identifies MindReset, Quote/0, the part, AdventureX 2026 as the designer, and CERN-OHL-P-2.0. Binary STL headers are limited to 80 bytes; full source and attribution details are provided here.

- Source: [MindReset Dot Open Platform](https://github.com/MindReset/dot_open_platform)
- Official website: [Dot by MindReset](https://dot.mindreset.tech)

These STEP and STL file-level markings do not add an embossed or engraved logo to the geometry.

## Usage Notes

- Inspect the STEP file in a CAD tool before machining, printing, or modifying the design.
- STL files do not encode units. Import the AdventureX 2026 meshes as millimeters and verify their scale before printing.
- Confirm tolerances against the exact display, PCB, battery, fasteners, and materials you use.
- STEP is an exchange format. If you need parametric editing, rebuild the model in your CAD tool or wait for a native source file release.
- No official drawing, render, or print profile is included. Print orientation, material, nozzle size, shrinkage, and post-processing all affect the result.

## License

Hardware design material in this folder is licensed under [CERN-OHL-P-2.0](../../../LICENSES/CERN-OHL-P-2.0.txt) unless a file states otherwise.

When redistributing modified designs, credit MindReset and retain the AdventureX design credit for the badge enclosure. See [NOTICE.md](../../../NOTICE.md) and the [trademark terms](../../../LICENSE.md#trademarks).

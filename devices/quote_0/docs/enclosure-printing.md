# Enclosure and Printing Notes

The public enclosure resources are:

| Design | File | Format |
| --- | --- | --- |
| Main Quote/0 enclosure | `enclosure/step/quote_0-enclosure.step` | STEP AP242 |
| AdventureX 2026 badge front shell | `enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-front.stl` | Binary STL |
| AdventureX 2026 badge back cover | `enclosure/stl/adventurex-2026/quote_0-adventurex-2026-badge-back-cover.stl` | Binary STL |

The STEP file is exported in millimeter units. STL files do not encode units; import the AdventureX 2026 meshes as millimeters and verify their scale before printing.

## Before Manufacturing

Inspect the model in your CAD tool and verify:

- Overall dimensions.
- Display opening and alignment.
- PCB mounting features.
- Battery clearance.
- Cable or flex routing.
- Button, port, or fastener clearance.
- Wall thickness.
- Assembly order.
- Material and process-specific tolerances.

## 3D Printing

The AdventureX 2026 badge enclosure includes a two-part printable STL set. No official print profile is included.

- Confirm units and scale after import.
- Select a print orientation appropriate for overhangs and supports.
- Check mesh integrity before slicing.
- Print a tolerance test before relying on a final part.
- Re-check fit with the exact display, PCB, battery, and fasteners you use.

## CAD Modification

The main enclosure STEP file is suitable for exchange and downstream mechanical work, but it is not the same as a native parametric CAD source file. The AdventureX 2026 files are triangulated meshes intended primarily for printing.

If you need editable parameters, import the STEP file into your CAD tool and rebuild editable features as needed.

## License

The enclosure file is published as hardware design material under CERN-OHL-P-2.0 unless a file states otherwise.

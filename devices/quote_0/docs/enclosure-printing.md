# Enclosure and Printing Notes

The current public enclosure file is:

```text
enclosure/step/quote_0-enclosure.step
```

It is a STEP AP242 exchange file exported in millimeter units.

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

No official STL or print profile is included in this release.

If you export your own STL:

- Choose mesh resolution intentionally.
- Confirm units after export.
- Check overhangs and support requirements.
- Print a tolerance test before relying on a final part.
- Re-check fit with the exact display, PCB, battery, and fasteners you use.

## CAD Modification

The STEP file is suitable for exchange and downstream mechanical work, but it is not the same as a native parametric CAD source file.

If you need editable parameters, import the STEP file into your CAD tool and rebuild editable features as needed.

## License

The enclosure file is published as hardware design material under CERN-OHL-P-2.0 unless a file states otherwise.


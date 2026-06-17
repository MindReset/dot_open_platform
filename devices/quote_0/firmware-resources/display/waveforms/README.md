# UC8251D Waveform Notes

The minimal UC8251D driver includes a full-refresh waveform/LUT table named `s_lut_gc` in:

```text
../drivers/uc8251d_minimal.c
```

The waveform data is redistributed here as part of the public Quote/0 display resources, based on the assumption that MindReset is authorized to publish and redistribute it.

## LUT Layout

The table contains 376 bytes split across the UC8251D LUT command registers:

| Command | Offset | Length | Purpose |
| --- | ---: | ---: | --- |
| `0x20` | `0` | `80` | VCOM LUT |
| `0x21` | `80` | `56` | White-to-white transition LUT |
| `0x22` | `136` | `80` | Black-to-white transition LUT |
| `0x23` | `216` | `80` | White-to-black transition LUT |
| `0x24` | `296` | `80` | Black-to-black transition LUT |

The driver loads the LUT before writing the old and new frame planes, then triggers a full display update with command `0x12`.

## Integration Rules

- Use the LUT with the UC8251D controller and the Quote/0 152 x 296 monochrome panel configuration.
- Keep the framebuffer format as 1bpp, where `1` means white and `0` means black.
- Treat waveform timing as display-specific. Do not assume it is safe for unrelated panels without validation.
- If you replace the display panel, validate the controller, resolution, voltage behavior, and waveform requirements before reusing this LUT.

## License

Waveform-related display resources in this package are published under the repository hardware/documentation license policy. Check `LICENSE.md` and `NOTICE.md` before redistributing modified versions.


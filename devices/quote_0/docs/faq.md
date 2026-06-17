# FAQ

## Is this the full Quote/0 product firmware?

No. This repository publishes open hardware resources and minimal firmware bring-up files. It does not include complete product firmware or application logic.

## Where are the official software APIs?

Start with the Developer Platform at https://dot.mindreset.tech/developers, then use the Developer Platform docs at https://dot.mindreset.tech/docs/service/open.

The most relevant content APIs are:

- Text API: https://dot.mindreset.tech/docs/service/open/text_api
- Image API: https://dot.mindreset.tech/docs/service/open/image_api
- Canvas API: https://dot.mindreset.tech/docs/service/open/canvas_api
- Skills: https://dot.mindreset.tech/docs/service/open/skill

## Where are community software and hardware examples?

Use Community Co-Creation at https://dot.mindreset.tech/docs/service/co_create.

- Software Co-Creation: https://dot.mindreset.tech/docs/service/co_create/software
- Hardware Co-Creation: https://dot.mindreset.tech/docs/service/co_create/hardware

## Can I write my own firmware?

Yes. Start with the GPIO pinout, display resources, and ESP-IDF example. The public driver is intentionally small so it can be inspected and ported.

## Which display driver should I use?

Use the standard driver unless the Dot. App device details show an Early Bird Edition label.

| Dot. App locale | Device name | Edition label | Driver |
| --- | --- | --- | --- |
| `zh-Hans-CN` | `摘录/0` | `首发版` | `uc8151_minimal.*` |
| `en-US` | `Quote/0` | `Early Bird Edition` | `uc8151_minimal.*` |
| `ja-JP` | `Quote/0` | `先発版です` | `uc8151_minimal.*` |

If no edition label is shown, use `uc8251d_minimal.*`.

## Can I manufacture or sell a derivative?

The included materials are published under open licenses that allow broad reuse. You must follow the license and attribution requirements in `LICENSE.md` and `NOTICE.md`. The licenses do not grant trademark rights.

## Can I use the Quote/0 name or MindReset logo?

You may use names for accurate attribution or compatibility statements. Do not use MindReset names, logos, or product identity in a way that suggests endorsement or official status.

## Are display waveforms redistributable?

This package treats the included standard and Early Bird Edition waveform/LUT data as authorized for public redistribution by MindReset. Do not add other vendor waveforms unless their redistribution rights are clear.

## Why is there no STL file?

The current release includes a STEP file. You can export STL from your CAD tool if needed, then validate print tolerances.

## Does the display use MISO?

No. The public Quote/0 display interface uses MOSI and CLK for SPI writes and does not use MISO.

## What does `GPIO20` do?

`GPIO20` controls display power. The minimal driver enables it during display operations and releases it when entering sleep.

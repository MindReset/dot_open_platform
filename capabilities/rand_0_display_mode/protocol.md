# Rand/0 Display Mode Protocol

This document describes the WebSocket protocol implemented by Rand/0 firmware `1.3.1`.

## Connection

Enter Display Mode from **Main menu → More → Display**. Rand/0 connects to a remembered Wi-Fi network and shows its local IP address when ready.

Connect to one of these endpoints:

| Endpoint | Binary frame | Format |
| --- | ---: | --- |
| `ws://<IP>/display/bw` | Exactly `5,000` bytes | 1 bit per pixel, black and white |
| `ws://<IP>/display/gray4` | Exactly `10,000` bytes | 2 bits per pixel, four gray levels |

The display is `200 × 200` pixels. Send one binary frame for each image.

## Frame encoding

Pixels are packed row by row, from left to right and then top to bottom. The highest bits represent the leftmost pixels.

### Black and white

- `1` means white; `0` means black.
- Each byte contains 8 pixels.
- The first pixel uses bit 7.

### Four gray levels

- Each pixel uses 2 bits.
- `00` is white, `01` is light gray, `10` is dark gray, and `11` is black.
- Each byte contains 4 pixels.
- The first pixel uses bits 7–6.

## Device messages

Rand/0 sends text JSON messages for button events and errors. A short press looks like this:

```json
{"type":"key","key":"up","action":"short"}
```

Possible frame errors include:

```json
{"type":"error","error":"expected_binary_5000"}
{"type":"error","error":"expected_binary_10000"}
{"type":"error","error":"inactive_client"}
{"type":"error","error":"no_memory"}
{"type":"error","error":"queue_busy"}
```

## Limits

- Only one client is active at a time. A new connection replaces the previous client.
- If the display is still refreshing when another frame arrives, Rand/0 keeps the latest frame and may drop intermediate frames.
- The connection has no additional login authentication. Use it only on a trusted local network.

## Minimal example

```js
const socket = new WebSocket("ws://192.168.1.100/display/bw");
socket.binaryType = "arraybuffer";
socket.onopen = () => socket.send(new Uint8Array(5000).fill(0xff));
socket.onmessage = (event) => console.log(event.data);
```

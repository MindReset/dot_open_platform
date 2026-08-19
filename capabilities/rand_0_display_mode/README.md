# Rand/0 Display Mode

Rand/0 Display Mode lets you build a small local tool that sends custom images to the device and receives its button events. It is a direct LAN connection: no Dot. App, Dot API, or custom firmware is required.

This package documents the Display Mode protocol implemented by Rand/0 firmware `1.3.1` and includes an official browser example.

## Quick start

Before you begin:

- Complete Wi-Fi Time Sync once so Rand/0 remembers a Wi-Fi network.
- Keep Rand/0 charged or connected to power.
- Connect your computer and Rand/0 to the same local network.

1. On Rand/0, open **Main menu → More → Display**.
2. Wait for the device to show its local IP address.
3. Serve the browser example from this directory:

   ```sh
   cd examples/web
   python3 -m http.server 8765
   ```

4. Open <http://127.0.0.1:8765/display_ws_test.html>.
5. Enter the IP address shown on Rand/0, connect, choose an image, and send it.

The device exits Display Mode when you long-press the top button.

## Example

- [Browser example](examples/web/display_ws_test.html)
- [Protocol reference](protocol.md)

The example is a dependency-free HTML file. It resizes an image to `200 × 200`, converts it to the selected frame format in the browser, sends it over WebSocket, and displays button events returned by Rand/0.

## Network and security

Display Mode is intended for a trusted local network. The device exposes its WebSocket endpoints without additional login authentication. Do not forward the device port to the internet or send sensitive content while using this capability.

The device allows one active client at a time. A new connection replaces the previous one, and frames sent faster than the e-ink display can refresh may be dropped so that only the latest frame is kept.

This is a device-local capability, not a Dot cloud API. It does not provide device identity, remote access, or firmware customization.

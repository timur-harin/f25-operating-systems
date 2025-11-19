Lab 12 Livecoding: I/O Peripheral Practice
==========================================

Goal
----
Step through the slide exercises: inspect `/proc/ioports`, read keyboard events, and emit shortcuts.

How to use
----------
1. Open `io_livecoding.c`.
2. Follow the `TODO` markers:
   - Exercise A: parse `/proc/ioports` (or sample file) and locate dma1/pic1/timer0.
   - Exercise B: read raw `struct input_event` entries from a device/saved capture.
   - Exercise C: detect combo shortcuts and print custom messages.
3. Build with `make`.
4. Run commands:
   - `./io_livecoding ioports /proc/ioports`
   - `sudo ./io_livecoding keyboard /dev/input/by-path/...`
   - `./io_livecoding shortcuts sample_events.bin`

Stretch ideas
-------------
- Support hotplug by watching `/dev/input` with `inotify`.
- Add JSON logging of events for later analysis.
- Export shortcut definitions to a config file for easier demo tweaks.



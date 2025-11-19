Lab 12: Input/Output & Event Devices

Overview
- Explore Linux peripheral discovery via `/proc/ioports`
- Simulate reading keyboard events from `/dev/input` and printing decoded output
- Detect key combinations (shortcuts) and discuss privilege requirements

Snippets

io_ports.c - Parse sample `/proc/ioports` output and highlight common controllers
keyboard_monitor.c - Decode synthetic `input_event` data and print event stream
shortcut_demo.c - Extend the monitor with combo detection and custom shortcuts

Build: `make`
Run: `./bin/<demo>`

Notes: Actual labs require sudo and direct device access; these demos simulate the flows in a safe environment.



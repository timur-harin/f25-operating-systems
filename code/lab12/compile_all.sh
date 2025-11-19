#!/bin/bash
set -e
echo "=== Lab 12: Input/Output & Event Devices ==="
make -C "$(dirname "$0")" clean && make -C "$(dirname "$0")"
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_io_ports.sh"
echo "  ./snippets/sh/run_keyboard_monitor.sh"
echo "  ./snippets/sh/run_shortcut_demo.sh"



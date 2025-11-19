#!/bin/bash
# Run all Lab 12 demos in sequence

set -e
cd "$(dirname "$0")"

echo "======================================================"
echo "Lab 12: Input/Output & Event Devices - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
bash ./snippets/sh/run_io_ports.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_keyboard_monitor.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_shortcut_demo.sh
echo ""

echo "======================================================"
echo "All Lab 12 demos completed!"
echo "======================================================"



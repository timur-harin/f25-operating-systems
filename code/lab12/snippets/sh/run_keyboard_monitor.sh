#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/keyboard_monitor ]; then
	make
fi
echo "--- Keyboard Monitor Demo ---"
./bin/keyboard_monitor



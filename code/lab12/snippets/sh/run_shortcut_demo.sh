#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/shortcut_demo ]; then
	make
fi
echo "--- Shortcut Detection Demo ---"
./bin/shortcut_demo



#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/cscan_disk ]; then
	make
fi
echo "--- C-SCAN Disk Scheduling ---"
./bin/cscan_disk



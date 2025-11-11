#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/scan_disk ]; then
	make
fi
echo "--- SCAN Disk Scheduling ---"
./bin/scan_disk



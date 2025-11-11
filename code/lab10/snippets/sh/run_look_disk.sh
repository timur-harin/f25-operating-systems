#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/look_disk ]; then
	make
fi
echo "--- LOOK Disk Scheduling ---"
./bin/look_disk



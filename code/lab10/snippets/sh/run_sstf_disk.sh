#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/sstf_disk ]; then
	make
fi
echo "--- SSTF Disk Scheduling ---"
./bin/sstf_disk



#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/fcfs_disk ]; then
	make
fi
echo "--- FCFS Disk Scheduling ---"
./bin/fcfs_disk



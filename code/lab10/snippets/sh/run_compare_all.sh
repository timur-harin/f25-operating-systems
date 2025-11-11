#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/compare_all ]; then
	make
fi
echo "--- Disk Scheduling: Compare All ---"
./bin/compare_all



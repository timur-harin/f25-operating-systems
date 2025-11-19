#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/deadlock_sim ]; then
	make
fi
echo "--- Deadlock Simulation ---"
./bin/deadlock_sim



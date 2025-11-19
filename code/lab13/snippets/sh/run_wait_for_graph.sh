#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/wait_for_graph ]; then
	make
fi
echo "--- Wait-For Graph Analysis ---"
./bin/wait_for_graph



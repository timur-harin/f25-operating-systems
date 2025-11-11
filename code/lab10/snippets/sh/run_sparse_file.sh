#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/sparse_file ]; then
	make
fi
echo "--- Sparse File ---"
./bin/sparse_file
echo ""
echo "Inspect with: ls -ls bin/sparse_demo.bin"



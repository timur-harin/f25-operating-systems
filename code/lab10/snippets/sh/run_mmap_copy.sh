#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/mmap_copy ]; then
	make
fi
echo "--- mmap Copy ---"
./bin/mmap_copy README.md bin/mmap_copy.out
echo ""
echo "Created bin/mmap_copy.out"



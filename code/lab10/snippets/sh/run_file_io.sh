#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/file_io ]; then
	make
fi
echo "--- File I/O ---"
./bin/file_io
echo ""
echo "Created ./bin/io_demo.txt"



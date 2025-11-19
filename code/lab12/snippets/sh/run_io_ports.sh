#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/io_ports ]; then
	make
fi
echo "--- /proc/ioports exploration ---"
./bin/io_ports



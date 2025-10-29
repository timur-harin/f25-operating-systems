#!/bin/bash
echo "=== Process Memory Maps Demo ==="
[ ! -f "bin/proc_maps" ] && echo "Error: Run 'make' first." && exit 1
./bin/proc_maps

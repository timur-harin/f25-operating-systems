#!/bin/bash
echo "=== Memory Mapping Demo ==="
[ ! -f "bin/mmap_demo" ] && echo "Error: Run 'make' first." && exit 1
./bin/mmap_demo

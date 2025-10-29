#!/bin/bash
echo "=== Page Replacement Algorithm Comparison ==="
[ ! -f "bin/compare_all" ] && echo "Error: Run 'make' first." && exit 1
./bin/compare_all

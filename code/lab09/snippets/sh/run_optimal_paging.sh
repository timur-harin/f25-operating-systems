#!/bin/bash
echo "=== Optimal Page Replacement Demo ==="
[ ! -f "bin/optimal_paging" ] && echo "Error: Run 'make' first." && exit 1
./bin/optimal_paging

#!/bin/bash
echo "=== FIFO Page Replacement Demo ==="
[ ! -f "bin/fifo_paging" ] && echo "Error: Run 'make' first." && exit 1
./bin/fifo_paging

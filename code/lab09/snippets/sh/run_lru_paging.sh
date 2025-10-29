#!/bin/bash
echo "=== LRU Page Replacement Demo ==="
[ ! -f "bin/lru_paging" ] && echo "Error: Run 'make' first." && exit 1
./bin/lru_paging

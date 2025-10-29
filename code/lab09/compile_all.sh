#!/bin/bash
set -e
echo "=== Lab 09: Page Replacement Algorithms ===" 
make clean && make
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_fifo_paging.sh"
echo "  ./snippets/sh/run_lru_paging.sh"
echo "  ./snippets/sh/run_optimal_paging.sh"
echo "  ./snippets/sh/run_compare_all.sh"


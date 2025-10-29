#!/bin/bash
# Run all Lab 09 demos in sequence

echo "======================================================"
echo "Lab 09: Page Replacement Algorithms - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
./snippets/sh/run_fifo_paging.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
./snippets/sh/run_lru_paging.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
./snippets/sh/run_optimal_paging.sh
echo ""
read -p "Press ENTER for comparison..."

echo ""
./snippets/sh/run_compare_all.sh
echo ""

echo "======================================================"
echo "All Lab 09 demos completed!"
echo "======================================================"


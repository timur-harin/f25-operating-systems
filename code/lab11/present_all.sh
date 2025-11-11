#!/bin/bash
# Run all Lab 11 demos in sequence

set -e
cd "$(dirname "$0")"

echo "======================================================"
echo "Lab 11: Alternative File Systems - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
bash ./snippets/sh/run_lfs_log.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_journaling_demo.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_cow_tree.sh
echo ""

echo "======================================================"
echo "All Lab 11 demos completed!"
echo "======================================================"



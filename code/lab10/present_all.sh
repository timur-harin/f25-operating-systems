#!/bin/bash
# Run all Lab 10 demos in sequence

set -e
cd "$(dirname "$0")"

echo "======================================================"
echo "Lab 10: Disk Scheduling Algorithms - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
bash ./snippets/sh/run_fcfs_disk.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_sstf_disk.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_scan_disk.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_cscan_disk.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_look_disk.sh
echo ""
read -p "Press ENTER for comparison..."

echo ""
bash ./snippets/sh/run_compare_all.sh
echo ""

echo "======================================================"
echo "All Lab 10 demos completed!"
echo "======================================================"



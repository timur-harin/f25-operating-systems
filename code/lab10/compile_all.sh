#!/bin/bash
set -e
echo "=== Lab 10: Disk Scheduling Algorithms ===" 
make -C "$(dirname "$0")" clean && make -C "$(dirname "$0")"
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_fcfs_disk.sh"
echo "  ./snippets/sh/run_sstf_disk.sh"
echo "  ./snippets/sh/run_scan_disk.sh"
echo "  ./snippets/sh/run_cscan_disk.sh"
echo "  ./snippets/sh/run_look_disk.sh"
echo "  ./snippets/sh/run_compare_all.sh"



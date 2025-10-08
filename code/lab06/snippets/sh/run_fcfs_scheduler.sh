#!/bin/bash
# Demo: First Come First Served (FCFS) scheduling algorithm

echo "=== FCFS Scheduler Demo ==="
echo "This demo simulates First Come First Served scheduling"
echo ""

if [ ! -f "bin/fcfs_scheduler" ]; then
    echo "Error: bin/fcfs_scheduler not found. Please run 'make' first."
    exit 1
fi

echo "Running with default processes..."
echo ""
./bin/fcfs_scheduler

echo ""
echo "---"
echo ""
echo "Running with custom processes (format: pid,at,bt)..."
echo "Processes: P1(0,3), P2(2,6), P3(4,4), P4(6,5)"
echo ""
./bin/fcfs_scheduler 1,0,3 2,2,6 3,4,4 4,6,5

echo ""
echo "Explanation:"
echo "- FCFS is the simplest scheduling algorithm (non-preemptive)"
echo "- Processes executed in order of arrival"
echo "- May suffer from convoy effect (long process blocks others)"
echo "- Formula: WT = TAT - BT, TAT = CT - AT"


#!/bin/bash
# Demo: Shortest Job First (SJF) scheduling algorithm

echo "=== SJF Scheduler Demo ==="
echo "This demo simulates Shortest Job First scheduling"
echo ""

if [ ! -f "bin/sjf_scheduler" ]; then
    echo "Error: bin/sjf_scheduler not found. Please run 'make' first."
    exit 1
fi

echo "Running with example processes..."
echo ""
./bin/sjf_scheduler

echo ""
echo "Explanation:"
echo "- SJF selects process with shortest burst time (non-preemptive)"
echo "- Gives minimum average waiting time (optimal)"
echo "- May cause starvation if short processes keep arriving"
echo "- Requires knowing burst time in advance (theoretical)"
echo "- Execution order differs from FCFS to minimize waiting"


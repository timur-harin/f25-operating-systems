#!/bin/bash
# Demo: Round Robin (RR) scheduling algorithm

echo "=== Round Robin Scheduler Demo ==="
echo "This demo simulates Round Robin scheduling with time quantum"
echo ""

if [ ! -f "bin/rr_scheduler" ]; then
    echo "Error: bin/rr_scheduler not found. Please run 'make' first."
    exit 1
fi

echo "Running with default time quantum (2)..."
echo ""
./bin/rr_scheduler

echo ""
echo "---"
echo ""
echo "Running with time quantum = 4..."
echo ""
./bin/rr_scheduler 4

echo ""
echo "Explanation:"
echo "- RR is preemptive, gives each process a time quantum"
echo "- After quantum expires, process goes to back of queue"
echo "- Fair CPU allocation, good for time-sharing systems"
echo "- Small quantum: more context switches, better response time"
echo "- Large quantum: approaches FCFS behavior"
echo "- Shows execution timeline with time slices"


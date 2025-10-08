#!/bin/bash
# Demo: alarm() and SIGALRM signal

echo "=== Alarm Signal Demo ==="
echo "This demo shows how to use alarm() to set timers"
echo ""

if [ ! -f "bin/alarm_demo" ]; then
    echo "Error: bin/alarm_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/alarm_demo"
echo ""
./bin/alarm_demo

echo ""
echo "Explanation:"
echo "- alarm(N) sends SIGALRM after N seconds"
echo "- SIGALRM can be caught with a signal handler"
echo "- Useful for timeouts and periodic tasks"
echo "- Child process sets 3-second alarm but runs for 5 seconds"
echo "- Handler executes at 3 seconds, then process continues"


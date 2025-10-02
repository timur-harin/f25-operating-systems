#!/bin/bash
# Demo: Race condition - multiple threads accessing shared data unsafely

echo "=== Race Condition Demo ==="
echo "This demo shows what happens when threads access shared data without synchronization"
echo ""

if [ ! -f "bin/race_condition" ]; then
    echo "Error: bin/race_condition not found. Please run 'make' first."
    exit 1
fi

echo "Running multiple times to observe race conditions:"
echo ""

for i in {1..5}; do
    echo "--- Run $i ---"
    ./bin/race_condition
    echo ""
done

echo "Explanation:"
echo "- Multiple threads increment a shared counter without protection"
echo "- counter++ is NOT atomic (read, increment, write)"
echo "- Race condition: threads interfere with each other's operations"
echo "- Results are non-deterministic and usually incorrect"
echo "- This is the CRITICAL SECTION problem"


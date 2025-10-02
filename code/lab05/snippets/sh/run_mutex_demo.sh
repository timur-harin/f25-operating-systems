#!/bin/bash
# Demo: Mutex - solving race condition with mutual exclusion

echo "=== Mutex Demo (Solving Race Condition) ==="
echo "This demo shows how mutexes prevent race conditions"
echo ""

if [ ! -f "bin/mutex_demo" ]; then
    echo "Error: bin/mutex_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/mutex_demo"
echo ""
./bin/mutex_demo

echo ""
echo "Explanation:"
echo "- pthread_mutex_lock() acquires exclusive access to critical section"
echo "- Only one thread can hold the mutex at a time"
echo "- Other threads block (wait) until mutex is released"
echo "- pthread_mutex_unlock() releases the mutex"
echo "- Result: Guaranteed correct counter value!"
echo ""
echo "Compare this to the race_condition demo - mutex ensures correctness"


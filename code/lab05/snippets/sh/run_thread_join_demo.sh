#!/bin/bash
# Demo: Thread joins and return values

echo "=== Thread Join Demo ==="
echo "This demo shows how pthread_join() waits for threads and retrieves return values"
echo ""

if [ ! -f "bin/thread_join_demo" ]; then
    echo "Error: bin/thread_join_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/thread_join_demo"
echo ""
./bin/thread_join_demo

echo ""
echo "Explanation:"
echo "- pthread_join() blocks until the specified thread terminates"
echo "- It retrieves the thread's return value (void pointer)"
echo "- Ensures proper cleanup and synchronization"
echo "- Main thread waits for all workers before proceeding"


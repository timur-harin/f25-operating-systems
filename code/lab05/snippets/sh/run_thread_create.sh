#!/bin/bash
# Demo: Basic thread creation with pthread_create and pthread_join

echo "=== Thread Creation Demo ==="
echo "This demo shows basic POSIX thread creation and joining"
echo ""

if [ ! -f "bin/thread_create" ]; then
    echo "Error: bin/thread_create not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/thread_create"
echo ""
./bin/thread_create

echo ""
echo "Explanation:"
echo "- pthread_create() spawns new threads within same process"
echo "- Threads share the same address space and resources"
echo "- pthread_join() waits for thread completion"
echo "- Threads may execute in parallel on multi-core systems"


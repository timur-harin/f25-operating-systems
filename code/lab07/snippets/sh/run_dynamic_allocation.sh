#!/bin/bash
# Demo: Dynamic memory allocation with malloc, calloc, realloc, free

echo "=== Dynamic Allocation Demo ==="
echo "This demo shows malloc, calloc, realloc, and proper memory management"
echo ""

if [ ! -f "bin/dynamic_allocation" ]; then
    echo "Error: bin/dynamic_allocation not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/dynamic_allocation"
echo ""
./bin/dynamic_allocation

echo ""
echo "Explanation:"
echo "- malloc(size):        Allocates uninitialized memory"
echo "- calloc(n, size):     Allocates zero-initialized memory"
echo "- realloc(ptr, size):  Resizes allocation, preserves data"
echo "- free(ptr):           Releases memory back to system"
echo ""
echo "Memory leak detection:"
echo "  valgrind ./bin/dynamic_allocation  # (if valgrind installed)"
echo "  leaks ./bin/dynamic_allocation     # (macOS)"


#!/bin/bash
# Demo: Worst Fit memory allocation algorithm

echo "=== Worst Fit Allocator Demo ==="
echo "This demo simulates the Worst Fit allocation strategy"
echo ""

if [ ! -f "bin/allocator_worstfit" ]; then
    echo "Error: bin/allocator_worstfit not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/allocator_worstfit"
echo ""
./bin/allocator_worstfit

echo ""
echo "Explanation:"
echo "- Worst Fit: Allocate from largest available block"
echo "- Goal: Leave large enough fragments for future use"
echo "- Slower: Must search entire free list"
echo "- Problem: Quickly breaks up all large blocks"
echo "- Performance: Generally poorest among the three strategies"


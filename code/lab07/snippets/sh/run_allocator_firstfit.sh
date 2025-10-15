#!/bin/bash
# Demo: First Fit memory allocation algorithm

echo "=== First Fit Allocator Demo ==="
echo "This demo simulates the First Fit allocation strategy"
echo ""

if [ ! -f "bin/allocator_firstfit" ]; then
    echo "Error: bin/allocator_firstfit not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/allocator_firstfit"
echo ""
./bin/allocator_firstfit

echo ""
echo "Explanation:"
echo "- First Fit: Search from beginning, use first block that fits"
echo "- Fast: Stops at first suitable block (no full search)"
echo "- Fragmentation: May create small unusable blocks at start"
echo "- Use case: When speed is priority over memory utilization"


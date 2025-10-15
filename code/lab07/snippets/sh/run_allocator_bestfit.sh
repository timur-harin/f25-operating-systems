#!/bin/bash
# Demo: Best Fit memory allocation algorithm

echo "=== Best Fit Allocator Demo ==="
echo "This demo simulates the Best Fit allocation strategy"
echo ""

if [ ! -f "bin/allocator_bestfit" ]; then
    echo "Error: bin/allocator_bestfit not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/allocator_bestfit"
echo ""
./bin/allocator_bestfit

echo ""
echo "Explanation:"
echo "- Best Fit: Find smallest block that fits the request"
echo "- Optimal: Minimizes wasted space per allocation"
echo "- Slower: Must search entire free list"
echo "- Fragmentation: May create many tiny unusable fragments"
echo "- Use case: When memory utilization is critical"


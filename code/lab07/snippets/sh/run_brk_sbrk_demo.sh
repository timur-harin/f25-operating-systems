#!/bin/bash
# Demo: Program break (brk/sbrk) for heap management

echo "=== brk/sbrk Demo ==="
echo "This demo shows low-level heap management with brk/sbrk"
echo ""

if [ ! -f "bin/brk_sbrk_demo" ]; then
    echo "Error: bin/brk_sbrk_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/brk_sbrk_demo"
echo ""
./bin/brk_sbrk_demo

echo ""
echo "Explanation:"
echo "- Program break marks the end of heap segment"
echo "- sbrk(0) returns current break without moving it"
echo "- sbrk(n) increases heap by n bytes"
echo "- brk(addr) sets break to specific address"
echo ""
echo "Historical note:"
echo "  Modern malloc often uses mmap for large allocations"
echo "  brk/sbrk mainly for small allocations in some implementations"


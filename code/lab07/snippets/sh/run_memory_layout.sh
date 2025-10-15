#!/bin/bash
# Demo: Memory layout of C program

echo "=== Memory Layout Demo ==="
echo "This demo shows the different memory segments of a C program"
echo ""

if [ ! -f "bin/memory_layout" ]; then
    echo "Error: bin/memory_layout not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/memory_layout"
echo ""
./bin/memory_layout

echo ""
echo "---"
echo ""
echo "Checking segment sizes with 'size' command:"
size bin/memory_layout

echo ""
echo "Explanation:"
echo "- text:  Code segment (executable instructions)"
echo "- data:  Initialized global/static variables"
echo "- bss:   Uninitialized global/static variables"
echo "- dec:   Total size in decimal"
echo "- hex:   Total size in hexadecimal"
echo ""
echo "Try: cat /proc/\$\$/maps  # to see memory mappings of current shell"


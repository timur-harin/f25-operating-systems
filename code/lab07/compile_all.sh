#!/bin/bash
# Compile all Lab 07 demos using the Makefile

set -e

echo "==========================================="
echo "Lab 07: Compiling Memory Management demos"
echo "==========================================="
echo ""

make clean
echo ""
make all

echo ""
echo "==========================================="
echo "Compilation complete!"
echo "==========================================="
echo ""
echo "Run individual demos with:"
echo ""
echo "Memory Fundamentals:"
echo "  ./snippets/sh/run_memory_layout.sh"
echo "  ./snippets/sh/run_pointer_basics.sh"
echo "  ./snippets/sh/run_dynamic_allocation.sh"
echo "  ./snippets/sh/run_brk_sbrk_demo.sh"
echo ""
echo "Memory Allocators:"
echo "  ./snippets/sh/run_allocator_firstfit.sh"
echo "  ./snippets/sh/run_allocator_bestfit.sh"
echo "  ./snippets/sh/run_allocator_worstfit.sh"
echo ""
echo "Or run all demos with:"
echo "  ./present_all.sh"


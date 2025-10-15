#!/bin/bash
# Run all Lab 07 demos in sequence for presentation

SCRIPT_DIR="snippets/sh"

echo "================================================================"
echo "Lab 07: Memory Management - Complete Demonstration"
echo "================================================================"
echo ""
echo "This script will run all demos in sequence."
echo "Press ENTER to continue between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

# Part 1: Memory Fundamentals
echo ""
echo ""
echo "=================================="
echo "PART 1: MEMORY FUNDAMENTALS"
echo "=================================="
echo ""
read -p "Press ENTER to continue..."

echo ""
echo ""
"$SCRIPT_DIR/run_memory_layout.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_pointer_basics.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_dynamic_allocation.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_brk_sbrk_demo.sh"
echo ""
read -p "Press ENTER for allocator demos..."

# Part 2: Memory Allocators
echo ""
echo ""
echo "=================================="
echo "PART 2: MEMORY ALLOCATORS"
echo "=================================="
echo ""
read -p "Press ENTER to continue..."

echo ""
echo ""
"$SCRIPT_DIR/run_allocator_firstfit.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_allocator_bestfit.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_allocator_worstfit.sh"
echo ""

echo ""
echo "================================================================"
echo "All Lab 07 demos completed!"
echo "================================================================"
echo ""
echo "Comparison of Allocation Strategies:"
echo "  First Fit:  Fast, may fragment beginning of memory"
echo "  Best Fit:   Optimal utilization, may create tiny fragments"
echo "  Worst Fit:  Leaves large fragments, poor overall performance"


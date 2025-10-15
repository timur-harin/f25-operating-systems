#!/bin/bash
# Demo: Pointer fundamentals

echo "=== Pointer Basics Demo ==="
echo "This demo explains pointers, dereferencing, and pointer arithmetic"
echo ""

if [ ! -f "bin/pointer_basics" ]; then
    echo "Error: bin/pointer_basics not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/pointer_basics"
echo ""
./bin/pointer_basics

echo ""
echo "Explanation:"
echo "- Pointers store memory addresses"
echo "- & operator: gets address of a variable"
echo "- * operator (declaration): declares a pointer"
echo "- * operator (dereference): accesses value at address"
echo "- Pointer arithmetic: ptr+1 advances by sizeof(type) bytes"
echo "- Pass by reference: function can modify caller's variables"


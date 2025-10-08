#!/bin/bash
# Demo: SIGUSR1 and SIGUSR2 for custom IPC

echo "=== SIGUSR1/SIGUSR2 Demo ==="
echo "This demo shows user-defined signals for custom behavior"
echo ""

if [ ! -f "bin/sigusr_demo" ]; then
    echo "Error: bin/sigusr_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/sigusr_demo"
echo ""
echo "Try entering:"
echo "  - A negative number (e.g., -5) -> triggers SIGUSR1"
echo "  - Non-numeric input (e.g., abc) -> triggers SIGUSR2"
echo "  - Valid positive number (e.g., 42) -> accepted"
echo "  - 'quit' to exit"
echo ""
./bin/sigusr_demo

echo ""
echo "Explanation:"
echo "- SIGUSR1 and SIGUSR2 are reserved for user-defined purposes"
echo "- Programs can raise() signals to themselves"
echo "- Useful for simple IPC and error handling"
echo "- Default action is terminate, but can be caught"


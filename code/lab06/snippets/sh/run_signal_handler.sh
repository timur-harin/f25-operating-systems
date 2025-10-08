#!/bin/bash
# Demo: Signal handler registration and custom behavior

echo "=== Signal Handler Demo ==="
echo "This demo shows how to register custom signal handlers"
echo ""

if [ ! -f "bin/signal_handler" ]; then
    echo "Error: bin/signal_handler not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/signal_handler"
echo ""
echo "Instructions:"
echo "  1. Press Ctrl+C once - handler catches it"
echo "  2. Press Ctrl+C again - default action (terminate)"
echo ""
echo "Program will auto-timeout after 15 seconds..."
echo ""

timeout 15 ./bin/signal_handler || echo ""

echo ""
echo "Explanation:"
echo "- signal() registers a custom handler for a signal"
echo "- First SIGINT: handler catches it and prints message"
echo "- Handler restores SIG_DFL (default) for next signal"
echo "- Second SIGINT: uses default action (terminate)"
echo "- This demonstrates signal handling and restoration"


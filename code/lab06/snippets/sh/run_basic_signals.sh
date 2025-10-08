#!/bin/bash
# Demo: Basic signals (SIGINT, SIGQUIT, SIGTERM)

echo "=== Basic Signals Demo ==="
echo "This demo shows different ways to terminate a process"
echo ""

if [ ! -f "bin/basic_signals" ]; then
    echo "Error: bin/basic_signals not found. Please run 'make' first."
    exit 1
fi

echo "Starting infinite loop program..."
echo "Try these commands:"
echo "  - Press Ctrl+C to send SIGINT"
echo "  - Press Ctrl+\\ to send SIGQUIT (creates core dump)"
echo "  - From another terminal: kill -SIGTERM <PID>"
echo ""
echo "Program will run for 10 seconds, then be auto-terminated..."
echo ""

timeout 10 ./bin/basic_signals || echo ""

echo ""
echo "Explanation:"
echo "- SIGINT (Ctrl+C): Interactive interrupt, default = terminate"
echo "- SIGQUIT (Ctrl+\\): Quit with core dump, default = terminate + dump"
echo "- SIGTERM: Polite termination request, can be caught/ignored"
echo "- SIGKILL: Forceful kill, cannot be caught or ignored"


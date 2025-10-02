#!/bin/bash
# Demo: Named pipes (FIFO) for IPC

echo "=== Named Pipe Demo (FIFO) ==="
echo "This demo shows how to use mkfifo() for process communication via filesystem"
echo ""

MESSAGE=${1:-"Hello via named pipe (FIFO)!"}

if [ ! -f "bin/named_pipe_demo" ]; then
    echo "Error: bin/named_pipe_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/named_pipe_demo \"$MESSAGE\""
echo ""
./bin/named_pipe_demo "$MESSAGE"

echo ""
echo "Explanation:"
echo "- mkfifo() creates a special file in /tmp"
echo "- Named pipes persist beyond process lifetime"
echo "- Can be used by unrelated processes"
echo "- Follows FIFO (First-In-First-Out) semantics"


#!/bin/bash
# Demo: Unnamed pipes for IPC between parent and child

echo "=== Pipe Demo (Unnamed Pipe) ==="
echo "This demo shows how to use pipe() for parent-child communication"
echo ""

MESSAGE=${1:-"Hello from parent via pipe!"}

if [ ! -f "bin/pipe_demo" ]; then
    echo "Error: bin/pipe_demo not found. Please run 'make' first."
    exit 1
fi

echo "Running: ./bin/pipe_demo \"$MESSAGE\""
echo ""
./bin/pipe_demo "$MESSAGE"

echo ""
echo "Explanation:"
echo "- Parent creates a pipe with pipe() syscall"
echo "- fork() creates child process"
echo "- Child reads from pipe[0], parent writes to pipe[1]"
echo "- Half-duplex communication (one-way)"


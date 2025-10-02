#!/bin/bash
# Compile all Lab 05 demos using the Makefile

set -e

echo "==================================="
echo "Lab 05: Compiling all IPC and Thread demos"
echo "==================================="
echo ""

make clean
echo ""
make all

echo ""
echo "==================================="
echo "Compilation complete!"
echo "==================================="
echo ""
echo "Run individual demos with:"
echo "  ./snippets/sh/run_pipe_demo.sh"
echo "  ./snippets/sh/run_named_pipe_demo.sh"
echo "  ./snippets/sh/run_thread_create.sh"
echo "  ./snippets/sh/run_race_condition.sh"
echo "  ./snippets/sh/run_mutex_demo.sh"
echo "  ./snippets/sh/run_thread_join_demo.sh"
echo ""
echo "Or run all demos with:"
echo "  ./present_all.sh"


#!/bin/bash
# Compile all Lab 06 demos using the Makefile

set -e

echo "=========================================="
echo "Lab 06: Compiling Process Scheduling and Signals demos"
echo "=========================================="
echo ""

make clean
echo ""
make all

echo ""
echo "=========================================="
echo "Compilation complete!"
echo "=========================================="
echo ""
echo "Run individual demos with:"
echo ""
echo "Signal Demos:"
echo "  ./snippets/sh/run_basic_signals.sh"
echo "  ./snippets/sh/run_signal_handler.sh"
echo "  ./snippets/sh/run_alarm_demo.sh"
echo "  ./snippets/sh/run_sigusr_demo.sh"
echo ""
echo "Scheduling Demos:"
echo "  ./snippets/sh/run_fcfs_scheduler.sh"
echo "  ./snippets/sh/run_sjf_scheduler.sh"
echo "  ./snippets/sh/run_rr_scheduler.sh"
echo ""
echo "Or run all demos with:"
echo "  ./present_all.sh"


#!/bin/bash
# Run all Lab 06 demos in sequence for presentation

SCRIPT_DIR="snippets/sh"

echo "============================================================="
echo "Lab 06: Process Scheduling and Signals - Complete Demo"
echo "============================================================="
echo ""
echo "This script will run all demos in sequence."
echo "Press ENTER to continue between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

# Signal Demos
echo ""
echo ""
echo "=============================="
echo "PART 1: SIGNAL DEMOS"
echo "=============================="
echo ""
read -p "Press ENTER to continue..."

echo ""
echo ""
"$SCRIPT_DIR/run_basic_signals.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_signal_handler.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_alarm_demo.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_sigusr_demo.sh"
echo ""
read -p "Press ENTER for scheduling demos..."

# Scheduling Demos
echo ""
echo ""
echo "=============================="
echo "PART 2: SCHEDULING ALGORITHMS"
echo "=============================="
echo ""
read -p "Press ENTER to continue..."

echo ""
echo ""
"$SCRIPT_DIR/run_fcfs_scheduler.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_sjf_scheduler.sh"
echo ""
read -p "Press ENTER for next demo..."

echo ""
echo ""
"$SCRIPT_DIR/run_rr_scheduler.sh"
echo ""

echo ""
echo "============================================================="
echo "All Lab 06 demos completed!"
echo "============================================================="


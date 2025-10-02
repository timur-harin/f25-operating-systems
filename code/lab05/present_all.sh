#!/bin/bash
# Run all Lab 05 demos in sequence for presentation

SCRIPT_DIR="snippets/sh"

echo "======================================================"
echo "Lab 05: IPC and POSIX Threads - Complete Demonstration"
echo "======================================================"
echo ""
echo "This script will run all demos in sequence."
echo "Press ENTER to continue between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

# Demo 1: Pipes
echo ""
echo ""
"$SCRIPT_DIR/run_pipe_demo.sh" "Message via pipe"
echo ""
read -p "Press ENTER for next demo..."

# Demo 2: Named Pipes
echo ""
echo ""
"$SCRIPT_DIR/run_named_pipe_demo.sh" "Message via FIFO"
echo ""
read -p "Press ENTER for next demo..."

# Demo 3: Thread Creation
echo ""
echo ""
"$SCRIPT_DIR/run_thread_create.sh"
echo ""
read -p "Press ENTER for next demo..."

# Demo 4: Race Condition
echo ""
echo ""
"$SCRIPT_DIR/run_race_condition.sh"
echo ""
read -p "Press ENTER for next demo..."

# Demo 5: Mutex
echo ""
echo ""
"$SCRIPT_DIR/run_mutex_demo.sh"
echo ""
read -p "Press ENTER for next demo..."

# Demo 6: Thread Join
echo ""
echo ""
"$SCRIPT_DIR/run_thread_join_demo.sh"
echo ""

echo ""
echo "======================================================"
echo "All Lab 05 demos completed!"
echo "======================================================"


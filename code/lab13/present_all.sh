#!/bin/bash
# Run all Lab 13 demos in sequence

set -e
cd "$(dirname "$0")"

echo "======================================================"
echo "Lab 13: Deadlocks & Resource Allocation - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
bash ./snippets/sh/run_deadlock_sim.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_wait_for_graph.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_request_processor.sh
echo ""

echo "======================================================"
echo "All Lab 13 demos completed!"
echo "======================================================"



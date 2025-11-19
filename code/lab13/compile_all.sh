#!/bin/bash
set -e
echo "=== Lab 13: Deadlocks & Resource Allocation ==="
make -C "$(dirname "$0")" clean && make -C "$(dirname "$0")"
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_deadlock_sim.sh"
echo "  ./snippets/sh/run_wait_for_graph.sh"
echo "  ./snippets/sh/run_request_processor.sh"



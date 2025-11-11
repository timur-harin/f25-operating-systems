#!/bin/bash
set -e
echo "=== Lab 11: Alternative File Systems ===" 
make -C "$(dirname "$0")" clean && make -C "$(dirname "$0")"
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_lfs_log.sh"
echo "  ./snippets/sh/run_journaling_demo.sh"
echo "  ./snippets/sh/run_cow_tree.sh"



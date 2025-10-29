#!/bin/bash
echo "=== Page Fault Demo ==="
[ ! -f "bin/page_fault_demo" ] && echo "Error: Run 'make' first." && exit 1
./bin/page_fault_demo

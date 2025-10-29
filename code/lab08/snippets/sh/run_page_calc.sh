#!/bin/bash
echo "=== Page Calculation Demo ==="
echo "Shows how virtual addresses are split into page numbers and offsets"
echo ""

[ ! -f "bin/page_calc" ] && echo "Error: Run 'make' first." && exit 1

./bin/page_calc

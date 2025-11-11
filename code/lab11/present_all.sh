#!/bin/bash
# Run all Lab 11 demos in sequence

set -e
cd "$(dirname "$0")"

echo "======================================================"
echo "Lab 11: Filesystems and UNIX I/O - Complete Demo"
echo "======================================================"
echo ""
echo "Press ENTER between demos, or Ctrl+C to exit."
echo ""

read -p "Press ENTER to start..."

echo ""
bash ./snippets/sh/run_list_dir.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_inode_info.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_file_io.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_sparse_file.sh
echo ""
read -p "Press ENTER for next demo..."

echo ""
bash ./snippets/sh/run_mmap_copy.sh
echo ""

echo "======================================================"
echo "All Lab 11 demos completed!"
echo "======================================================"



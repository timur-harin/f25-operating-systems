#!/bin/bash
set -e
echo "=== Lab 10: Filesystems and UNIX I/O ===" 
make -C "$(dirname "$0")" clean && make -C "$(dirname "$0")"
echo ""
echo "Run demos:"
echo "  ./snippets/sh/run_list_dir.sh"
echo "  ./snippets/sh/run_inode_info.sh"
echo "  ./snippets/sh/run_file_io.sh"
echo "  ./snippets/sh/run_sparse_file.sh"
echo "  ./snippets/sh/run_mmap_copy.sh"



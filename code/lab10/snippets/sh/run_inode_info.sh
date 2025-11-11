#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/inode_info ]; then
	make
fi
echo "--- Inode Info ---"
./bin/inode_info README.md



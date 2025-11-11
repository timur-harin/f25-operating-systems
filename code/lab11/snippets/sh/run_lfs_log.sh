#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/lfs_log ]; then
	make
fi
echo "--- LFS Log Demo ---"
./bin/lfs_log



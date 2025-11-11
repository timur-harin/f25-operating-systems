#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/cow_tree ]; then
	make
fi
echo "--- Copy-on-Write Tree Demo ---"
./bin/cow_tree



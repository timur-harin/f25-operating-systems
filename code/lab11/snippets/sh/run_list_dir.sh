#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/list_dir ]; then
	make
fi
echo "--- Directory Listing ---"
./bin/list_dir .



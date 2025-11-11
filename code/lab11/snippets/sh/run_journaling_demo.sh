#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/journaling_demo ]; then
	make
fi
echo "--- Journaling Demo ---"
./bin/journaling_demo



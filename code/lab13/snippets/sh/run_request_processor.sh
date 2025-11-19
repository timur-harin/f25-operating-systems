#!/bin/bash
set -e
cd "$(dirname "$0")/../.."
if [ ! -x ./bin/request_processor ]; then
	make
fi
echo "--- Request Processor ---"
./bin/request_processor



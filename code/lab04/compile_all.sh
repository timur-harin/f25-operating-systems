#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

make -C "$SCRIPT_DIR" all | cat

echo "Built binaries in $SCRIPT_DIR/bin:" 
ls -l "$SCRIPT_DIR/bin" | cat



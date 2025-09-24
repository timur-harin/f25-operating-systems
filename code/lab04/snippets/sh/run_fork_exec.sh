#!/usr/bin/env bash
set -euo pipefail

DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
BIN="$DIR/bin/fork_exec"

if [[ ! -x "$BIN" ]]; then
  echo "Building fork_exec demo..."
  make -C "$DIR" bin/fork_exec | cat
fi

"$BIN"



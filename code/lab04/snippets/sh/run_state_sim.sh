#!/usr/bin/env bash
set -euo pipefail

DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
BIN="$DIR/bin/state_sim"

if [[ ! -x "$BIN" ]]; then
  echo "Building state simulator..."
  make -C "$DIR" bin/state_sim | cat
fi

"$BIN" ${1:-3}



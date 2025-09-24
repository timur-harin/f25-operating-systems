#!/usr/bin/env bash
set -euo pipefail

DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
BIN="$DIR/bin/orphan"

if [[ ! -x "$BIN" ]]; then
  echo "Building orphan demo..."
  make -C "$DIR" bin/orphan | cat
fi

"$BIN"

echo "Observe child adoption:"
OS=$(uname -s)
if command -v pstree >/dev/null 2>&1; then
  pstree -p $$ | cat
else
  if [[ "$OS" == "Darwin" ]]; then
    ps -Ao pid,ppid,pgid,state,command | head -20 | cat
  else
    ps -e --forest -o pid,ppid,pgid,stat,cmd | head -40 | cat
  fi
fi



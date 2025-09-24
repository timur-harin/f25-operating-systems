#!/usr/bin/env bash
set -euo pipefail

DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
BIN="$DIR/bin/zombie"

if [[ ! -x "$BIN" ]]; then
  echo "Building zombie demo..."
  make -C "$DIR" bin/zombie | cat
fi

"$BIN" &
PID=$!
echo "Started zombie parent PID=$PID"

OS=$(uname -s)
if command -v pstree >/dev/null 2>&1; then
  echo "Observing with pstree:"
  if [[ "$OS" == "Darwin" ]]; then
    pstree -w -p "$PID" | cat
  else
    pstree -p -h "$PID" | cat
  fi
else
  if [[ "$OS" == "Darwin" ]]; then
    echo "pstree not found; using ps"
    ps -o pid,ppid,pgid,state,command -p "$PID" | cat
  else
    ps -e --forest -o pid,ppid,pgid,stat,cmd | grep "$PID" -n --color=never | cat || true
  fi
fi

wait "$PID"



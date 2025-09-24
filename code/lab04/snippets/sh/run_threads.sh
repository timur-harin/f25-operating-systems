#!/usr/bin/env bash
set -euo pipefail

DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." &>/dev/null && pwd)
BIN="$DIR/bin/threads_demo"

if [[ ! -x "$BIN" ]]; then
  echo "Building threads demo..."
  make -C "$DIR" bin/threads_demo | cat
fi

echo "Run without mutex (expect races):"
"$BIN" --threads 8 --iters 200000

echo
echo "Run with mutex (no races):"
"$BIN" --threads 8 --iters 200000 --mutex

echo
echo "Inspect threads in another terminal:"
echo "  Linux: ps -eL -o pid,tid,stat,cmd | grep $(basename "$BIN")"
echo "  macOS: top -H -pid <PID>   or   ps -M -p <PID>"



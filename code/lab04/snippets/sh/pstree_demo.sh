#!/usr/bin/env bash
set -euo pipefail

OS=$(uname -s)
echo "OS: $OS"

if ! command -v pstree >/dev/null 2>&1; then
  echo "pstree not found. Install it:"
  if [[ "$OS" == "Darwin" ]]; then
    echo "  brew install pstree"
  else
    echo "  sudo apt-get install -y psmisc    # or your distro equivalent"
  fi
  exit 1
fi

PID=${1:-$$}
echo "Demonstrating pstree around PID=$PID"

echo "\n1) Basic tree"
pstree "$PID" | cat

echo "\n2) With PIDs (-p)"
pstree -p "$PID" | cat

if [[ "$OS" == "Darwin" ]]; then
  echo "\n3) Wide output (-w) (macOS pstree has no -a/-h)"
  pstree -w -p "$PID" | cat || true
  echo "\n4) Graphics UTF-8 (-g 3)"
  pstree -g 3 -p "$PID" | cat || true
else
  echo "\n3) With arguments (-a)"
  pstree -a -p "$PID" | cat
  echo "\n4) Highlight current process (-h)"
  pstree -h -a -p "$PID" | cat
  echo "\n5) Show process groups (-g)"
  pstree -g -a -p "$PID" | cat
fi

echo "\nTip: Run this script in another tab while executing fork/zombie/orphan demos."



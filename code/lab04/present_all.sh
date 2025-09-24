#!/usr/bin/env bash
set -euo pipefail

OS=$(uname -s)
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

PAUSE=1
if [[ "${1:-}" == "--no-pause" ]]; then
  PAUSE=0
fi

pause() {
  if [[ $PAUSE -eq 1 ]]; then
    read -r -p "Press Enter to continue..." _
  fi
}

echo "[1/7] Build all demos"
bash "$SCRIPT_DIR/compile_all.sh" | cat
pause

echo "[2/7] pstree visualization demo"
bash "$SCRIPT_DIR/snippets/sh/pstree_demo.sh" | cat
pause

echo "[3/7] fork + exec demo"
bash "$SCRIPT_DIR/snippets/sh/run_fork_exec.sh" | cat
pause

echo "[4/7] orphan process demo"
bash "$SCRIPT_DIR/snippets/sh/run_orphan.sh" | cat
pause

echo "[5/7] zombie process demo (runs ~30s)"
echo "Tip: open another terminal and run: pstree -p <parentPID> (macOS: use -w -p)"
bash "$SCRIPT_DIR/snippets/sh/run_zombie.sh" | cat
pause

echo "[6/7] threads demo (race vs mutex)"
bash "$SCRIPT_DIR/snippets/sh/run_threads.sh" | cat
pause

echo "[7/7] process state simulator"
bash "$SCRIPT_DIR/snippets/sh/run_state_sim.sh" 2 | cat

echo "All demos completed."



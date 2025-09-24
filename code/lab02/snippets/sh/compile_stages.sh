#!/usr/bin/env bash
set -euo pipefail

# Usage: ./compile_stages.sh main.c
src=${1:-main.c}
base=${src%.*}

echo "[1] Preprocess -> ${base}.i"
gcc -E "$src" -o "${base}.i"

echo "[2] Compile to assembly -> ${base}.s"
gcc -S "$src" -o "${base}.s"

echo "[3] Compile to object -> ${base}.o"
gcc -c "$src" -o "${base}.o"

echo "[4] Link to executable -> ${base}.out"
gcc "$src" -o "${base}.out"

echo "Done. Try running: ./${base}.out"



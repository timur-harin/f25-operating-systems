#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"

SRC=main.c

echo "[1] Preprocess -> main.i"
gcc -E "$SRC" -o main.i

echo "[2] Compile to assembly -> main.asm"
gcc -S "$SRC" -o main.asm

echo "[3] Compile to object -> main.obj (aka .o)"
gcc -c "$SRC" -o main.obj

echo "[4] Link to executable -> main.out"
gcc "$SRC" -o main.out

echo "Run: ./main.out"



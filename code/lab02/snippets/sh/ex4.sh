#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -std=c11 -O2 ../c/count_chars_ex4.c -o ex4.out
./ex4.out Innopolis



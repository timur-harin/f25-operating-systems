#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -std=c11 -O2 ../c/convert_base_ex3.c -o ex3.out
echo "1234 8 2" | ./ex3.out



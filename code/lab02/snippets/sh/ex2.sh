#!/usr/bin/env bash
set -euo pipefail
gcc -Wall -Wextra -std=c11 -O2 ../c/reverse_until_dot_ex2.c -o ex2.out
printf "%s" "C language. is easy and simple." | ./ex2.out



#!/usr/bin/env bash
set -euo pipefail
gcc -std=c11 -Wall -Wextra -O2 \
  /Users/timur/develop/labs/os_ta/code/lab03/snippets/c/ex2.c \
  -lm \
  -o /Users/timur/develop/labs/os_ta/code/lab03/snippets/ex2 && \
  /Users/timur/develop/labs/os_ta/code/lab03/snippets/ex2 | cat




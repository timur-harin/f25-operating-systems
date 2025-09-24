#!/usr/bin/env bash
set -euo pipefail
gcc -std=c11 -Wall -Wextra -O2 \
  /Users/timur/develop/labs/os_ta/code/lab03/snippets/c/ex1.c \
  -o /Users/timur/develop/labs/os_ta/code/lab03/snippets/ex1 && \
  /Users/timur/develop/labs/os_ta/code/lab03/snippets/ex1 | cat




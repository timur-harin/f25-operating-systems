# Makefile for Lab 09: Page Replacement Algorithms

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

TARGETS = $(BIN_DIR)/fifo_paging $(BIN_DIR)/lru_paging \
          $(BIN_DIR)/optimal_paging $(BIN_DIR)/compare_all

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 09 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"


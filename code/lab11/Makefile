# Makefile for Lab 11: Alternative File Systems

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

TARGETS = $(BIN_DIR)/lfs_log $(BIN_DIR)/journaling_demo \
          $(BIN_DIR)/cow_tree

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 11 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"



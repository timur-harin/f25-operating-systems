# Makefile for Lab 13: Deadlocks & Resource Allocation

CC = gcc
CFLAGS = -Wall -Wextra -O2 -pthread
SRC_DIR = snippets/c
BIN_DIR = bin

TARGETS = $(BIN_DIR)/deadlock_sim $(BIN_DIR)/wait_for_graph \
          $(BIN_DIR)/request_processor

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 13 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"



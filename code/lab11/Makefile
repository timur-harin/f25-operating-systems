# Makefile for Lab 11: Filesystems and UNIX I/O

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

TARGETS = $(BIN_DIR)/list_dir $(BIN_DIR)/inode_info \
          $(BIN_DIR)/file_io $(BIN_DIR)/sparse_file \
          $(BIN_DIR)/mmap_copy

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



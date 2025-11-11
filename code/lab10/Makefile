# Makefile for Lab 10: Disk Scheduling Algorithms

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

TARGETS = $(BIN_DIR)/fcfs_disk $(BIN_DIR)/sstf_disk \
          $(BIN_DIR)/scan_disk $(BIN_DIR)/cscan_disk \
          $(BIN_DIR)/look_disk $(BIN_DIR)/compare_all

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 10 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"



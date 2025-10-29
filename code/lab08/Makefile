# Makefile for Lab 08: Virtual Memory

CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm
SRC_DIR = snippets/c
BIN_DIR = bin

SRCS = $(SRC_DIR)/page_calc.c $(SRC_DIR)/proc_maps.c \
       $(SRC_DIR)/page_fault_demo.c $(SRC_DIR)/mmap_demo.c

TARGETS = $(BIN_DIR)/page_calc $(BIN_DIR)/proc_maps \
          $(BIN_DIR)/page_fault_demo $(BIN_DIR)/mmap_demo

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 08 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"


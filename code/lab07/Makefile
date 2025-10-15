# Makefile for Lab 07: Memory Management
# Compiles all demo programs

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

# Memory fundamentals sources
MEMORY_LAYOUT_SRC = $(SRC_DIR)/memory_layout.c
POINTER_BASICS_SRC = $(SRC_DIR)/pointer_basics.c
DYNAMIC_ALLOCATION_SRC = $(SRC_DIR)/dynamic_allocation.c
BRK_SBRK_DEMO_SRC = $(SRC_DIR)/brk_sbrk_demo.c

# Allocator sources
ALLOCATOR_FIRSTFIT_SRC = $(SRC_DIR)/allocator_firstfit.c
ALLOCATOR_BESTFIT_SRC = $(SRC_DIR)/allocator_bestfit.c
ALLOCATOR_WORSTFIT_SRC = $(SRC_DIR)/allocator_worstfit.c

# Memory fundamentals binaries
MEMORY_LAYOUT_BIN = $(BIN_DIR)/memory_layout
POINTER_BASICS_BIN = $(BIN_DIR)/pointer_basics
DYNAMIC_ALLOCATION_BIN = $(BIN_DIR)/dynamic_allocation
BRK_SBRK_DEMO_BIN = $(BIN_DIR)/brk_sbrk_demo

# Allocator binaries
ALLOCATOR_FIRSTFIT_BIN = $(BIN_DIR)/allocator_firstfit
ALLOCATOR_BESTFIT_BIN = $(BIN_DIR)/allocator_bestfit
ALLOCATOR_WORSTFIT_BIN = $(BIN_DIR)/allocator_worstfit

# All targets
TARGETS = $(MEMORY_LAYOUT_BIN) $(POINTER_BASICS_BIN) $(DYNAMIC_ALLOCATION_BIN) \
          $(BRK_SBRK_DEMO_BIN) $(ALLOCATOR_FIRSTFIT_BIN) $(ALLOCATOR_BESTFIT_BIN) \
          $(ALLOCATOR_WORSTFIT_BIN)

.PHONY: all clean fundamentals allocators

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 07 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Memory fundamentals
fundamentals: $(MEMORY_LAYOUT_BIN) $(POINTER_BASICS_BIN) $(DYNAMIC_ALLOCATION_BIN) $(BRK_SBRK_DEMO_BIN)
	@echo "✓ Memory fundamentals demos compiled"

$(MEMORY_LAYOUT_BIN): $(MEMORY_LAYOUT_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(POINTER_BASICS_BIN): $(POINTER_BASICS_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(DYNAMIC_ALLOCATION_BIN): $(DYNAMIC_ALLOCATION_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(BRK_SBRK_DEMO_BIN): $(BRK_SBRK_DEMO_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

# Memory allocators
allocators: $(ALLOCATOR_FIRSTFIT_BIN) $(ALLOCATOR_BESTFIT_BIN) $(ALLOCATOR_WORSTFIT_BIN)
	@echo "✓ Allocator demos compiled"

$(ALLOCATOR_FIRSTFIT_BIN): $(ALLOCATOR_FIRSTFIT_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(ALLOCATOR_BESTFIT_BIN): $(ALLOCATOR_BESTFIT_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(ALLOCATOR_WORSTFIT_BIN): $(ALLOCATOR_WORSTFIT_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"


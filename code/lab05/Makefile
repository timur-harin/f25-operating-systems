# Makefile for Lab 05: IPC and Threads
# Compiles all demo programs

CC = gcc
CFLAGS = -Wall -Wextra -O2
PTHREAD_FLAGS = -pthread
SRC_DIR = snippets/c
BIN_DIR = bin

# Source files
PIPE_SRC = $(SRC_DIR)/pipe_demo.c
NAMED_PIPE_SRC = $(SRC_DIR)/named_pipe_demo.c
THREAD_CREATE_SRC = $(SRC_DIR)/thread_create.c
RACE_CONDITION_SRC = $(SRC_DIR)/race_condition.c
MUTEX_DEMO_SRC = $(SRC_DIR)/mutex_demo.c
THREAD_JOIN_SRC = $(SRC_DIR)/thread_join_demo.c

# Binaries
PIPE_BIN = $(BIN_DIR)/pipe_demo
NAMED_PIPE_BIN = $(BIN_DIR)/named_pipe_demo
THREAD_CREATE_BIN = $(BIN_DIR)/thread_create
RACE_CONDITION_BIN = $(BIN_DIR)/race_condition
MUTEX_DEMO_BIN = $(BIN_DIR)/mutex_demo
THREAD_JOIN_BIN = $(BIN_DIR)/thread_join_demo

# All targets
TARGETS = $(PIPE_BIN) $(NAMED_PIPE_BIN) $(THREAD_CREATE_BIN) \
          $(RACE_CONDITION_BIN) $(MUTEX_DEMO_BIN) $(THREAD_JOIN_BIN)

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 05 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# IPC demos (no pthread required)
$(PIPE_BIN): $(PIPE_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(NAMED_PIPE_BIN): $(NAMED_PIPE_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

# Thread demos (require pthread)
$(THREAD_CREATE_BIN): $(THREAD_CREATE_SRC)
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(RACE_CONDITION_BIN): $(RACE_CONDITION_SRC)
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(MUTEX_DEMO_BIN): $(MUTEX_DEMO_SRC)
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(THREAD_JOIN_BIN): $(THREAD_JOIN_SRC)
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"


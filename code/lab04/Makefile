CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra -std=c11
LDFLAGS ?=

SRC_DIR := snippets/c
BIN_DIR := bin

PROGRAMS := \
  zombie \
  orphan \
  fork_exec \
  threads_demo \
  state_sim

SRCS := $(addprefix $(SRC_DIR)/, \
  zombie.c \
  orphan.c \
  fork_exec.c \
  threads_demo.c \
  state_sim.c)

BINS := $(addprefix $(BIN_DIR)/, $(PROGRAMS))

.PHONY: all clean dirs

all: dirs $(BINS)

dirs:
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/zombie: $(SRC_DIR)/zombie.c
	$(CC) $(CFLAGS) $< -o $$(dirname $@)/$$(basename $@) $(LDFLAGS)

$(BIN_DIR)/orphan: $(SRC_DIR)/orphan.c
	$(CC) $(CFLAGS) $< -o $$(dirname $@)/$$(basename $@) $(LDFLAGS)

$(BIN_DIR)/fork_exec: $(SRC_DIR)/fork_exec.c
	$(CC) $(CFLAGS) $< -o $$(dirname $@)/$$(basename $@) $(LDFLAGS)

$(BIN_DIR)/threads_demo: $(SRC_DIR)/threads_demo.c
	$(CC) $(CFLAGS) $< -o $$(dirname $@)/$$(basename $@) -pthread $(LDFLAGS)

$(BIN_DIR)/state_sim: $(SRC_DIR)/state_sim.c
	$(CC) $(CFLAGS) $< -o $$(dirname $@)/$$(basename $@) $(LDFLAGS)

clean:
	rm -f $(BINS)


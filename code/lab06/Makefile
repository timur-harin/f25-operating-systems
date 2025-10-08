# Makefile for Lab 06: Process Scheduling and Signals
# Compiles all demo programs

CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC_DIR = snippets/c
BIN_DIR = bin

# Signal demo sources
BASIC_SIGNALS_SRC = $(SRC_DIR)/basic_signals.c
SIGNAL_HANDLER_SRC = $(SRC_DIR)/signal_handler.c
ALARM_DEMO_SRC = $(SRC_DIR)/alarm_demo.c
SIGUSR_DEMO_SRC = $(SRC_DIR)/sigusr_demo.c

# Scheduling demo sources
FCFS_SCHEDULER_SRC = $(SRC_DIR)/fcfs_scheduler.c
SJF_SCHEDULER_SRC = $(SRC_DIR)/sjf_scheduler.c
RR_SCHEDULER_SRC = $(SRC_DIR)/rr_scheduler.c

# Signal demo binaries
BASIC_SIGNALS_BIN = $(BIN_DIR)/basic_signals
SIGNAL_HANDLER_BIN = $(BIN_DIR)/signal_handler
ALARM_DEMO_BIN = $(BIN_DIR)/alarm_demo
SIGUSR_DEMO_BIN = $(BIN_DIR)/sigusr_demo

# Scheduling demo binaries
FCFS_SCHEDULER_BIN = $(BIN_DIR)/fcfs_scheduler
SJF_SCHEDULER_BIN = $(BIN_DIR)/sjf_scheduler
RR_SCHEDULER_BIN = $(BIN_DIR)/rr_scheduler

# All targets
TARGETS = $(BASIC_SIGNALS_BIN) $(SIGNAL_HANDLER_BIN) $(ALARM_DEMO_BIN) \
          $(SIGUSR_DEMO_BIN) $(FCFS_SCHEDULER_BIN) $(SJF_SCHEDULER_BIN) \
          $(RR_SCHEDULER_BIN)

.PHONY: all clean signals schedulers

all: $(BIN_DIR) $(TARGETS)
	@echo "✓ All Lab 06 demos compiled successfully!"

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Signal demos
signals: $(BASIC_SIGNALS_BIN) $(SIGNAL_HANDLER_BIN) $(ALARM_DEMO_BIN) $(SIGUSR_DEMO_BIN)
	@echo "✓ Signal demos compiled"

$(BASIC_SIGNALS_BIN): $(BASIC_SIGNALS_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(SIGNAL_HANDLER_BIN): $(SIGNAL_HANDLER_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(ALARM_DEMO_BIN): $(ALARM_DEMO_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(SIGUSR_DEMO_BIN): $(SIGUSR_DEMO_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

# Scheduling demos
schedulers: $(FCFS_SCHEDULER_BIN) $(SJF_SCHEDULER_BIN) $(RR_SCHEDULER_BIN)
	@echo "✓ Scheduler demos compiled"

$(FCFS_SCHEDULER_BIN): $(FCFS_SCHEDULER_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(SJF_SCHEDULER_BIN): $(SJF_SCHEDULER_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

$(RR_SCHEDULER_BIN): $(RR_SCHEDULER_SRC)
	$(CC) $(CFLAGS) -o $@ $<
	@echo "✓ Compiled: $@"

clean:
	rm -rf $(BIN_DIR)
	@echo "✓ Cleaned all binaries"


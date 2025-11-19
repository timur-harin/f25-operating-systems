# Livecoding Makefile for Lab 13

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = deadlock_workshop

.PHONY: all clean

all: $(TARGET)
	@echo "✓ Built livecoding binary: $(TARGET)"

$(TARGET): deadlock_workshop.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned livecoding artifacts"



# Livecoding Makefile for Lab 12

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = io_livecoding

.PHONY: all clean

all: $(TARGET)
	@echo "✓ Built livecoding binary: $(TARGET)"

$(TARGET): io_livecoding.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned livecoding artifacts"



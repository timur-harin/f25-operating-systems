# Livecoding Makefile for Lab 10

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = fs_workshop

.PHONY: all clean

all: $(TARGET)
	@echo "✓ Built livecoding binary: $(TARGET)"

$(TARGET): fs_workshop.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned livecoding artifacts"



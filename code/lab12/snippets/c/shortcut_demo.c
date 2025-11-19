#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned short code;
	int value;
} key_event;

enum {
	KEY_PRESSED = 1,
	KEY_RELEASED = 0,
};

static const key_event demo_stream[] = {
	{0x0019, KEY_PRESSED},  // P
	{0x0012, KEY_PRESSED},  // E
	{0x0012, KEY_RELEASED},
	{0x0019, KEY_RELEASED},
	{0x002e, KEY_PRESSED},  // C
	{0x001e, KEY_PRESSED},  // A
	{0x0019, KEY_PRESSED},  // P
	{0x002e, KEY_RELEASED},
	{0x001e, KEY_RELEASED},
	{0x0019, KEY_RELEASED},
	{0x0021, KEY_PRESSED},  // F
	{0x0018, KEY_PRESSED},  // O
	{0x001c, KEY_PRESSED},  // L
	{0x0018, KEY_RELEASED},
	{0x001c, KEY_RELEASED},
	{0x0021, KEY_RELEASED},
};

static bool pressed[0x100];

static bool combo_active(const unsigned short *combo, size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (!pressed[combo[i]]) return false;
	}
	return true;
}

static void check_shortcuts(void) {
	const unsigned short pe[] = {0x0019, 0x0012};          // P+E
	const unsigned short cap[] = {0x002e, 0x001e, 0x0019}; // C+A+P
	const unsigned short fol[] = {0x0021, 0x0018, 0x001c}; // custom F+O+L

	if (combo_active(pe, 2)) {
		puts("[shortcut] I passed the Exam!");
	}
	if (combo_active(cap, 3)) {
		puts("[shortcut] Get some cappuccino!");
	}
	if (combo_active(fol, 3)) {
		puts("[shortcut] Follow the flow!");
	}
}

static void handle_event(const key_event *ev) {
	pressed[ev->code] = (ev->value == KEY_PRESSED);
	printf("Event %-8s code=0x%04x (%u)\n",
	       ev->value ? "PRESSED" : "RELEASED",
	       ev->code,
	       ev->code);
	if (ev->value == KEY_PRESSED) {
		check_shortcuts();
	}
}

int main(void) {
	puts("Shortcut monitor demo");
	puts("Available combos:");
	puts("  P+E -> \"I passed the Exam!\"");
	puts("  C+A+P -> \"Get some cappuccino!\"");
	puts("  F+O+L -> \"Follow the flow!\"");
	puts("");
	for (size_t i = 0; i < sizeof(demo_stream)/sizeof(demo_stream[0]); i++) {
		handle_event(&demo_stream[i]);
	}
	puts("\nExtend: load live events from /dev/input and reuse this logic.");
	return 0;
}



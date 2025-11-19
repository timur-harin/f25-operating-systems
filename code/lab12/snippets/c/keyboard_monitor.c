#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct {
	struct timeval time;
	unsigned short type;
	unsigned short code;
	int value;
} input_event_sim;

enum {
	EV_KEY = 0x01,
	KEY_PRESSED = 1,
	KEY_RELEASED = 0,
	KEY_REPEAT = 2,
};

static const input_event_sim events[] = {
	{{0,0}, EV_KEY, 0x0013, KEY_PRESSED},   // R
	{{0,0}, EV_KEY, 0x0013, KEY_RELEASED},
	{{0,0}, EV_KEY, 0x0018, KEY_PRESSED},   // O
	{{0,0}, EV_KEY, 0x0018, KEY_RELEASED},
	{{0,0}, EV_KEY, 0x0012, KEY_PRESSED},   // E
	{{0,0}, EV_KEY, 0x0012, KEY_RELEASED},
	{{0,0}, EV_KEY, 0x002d, KEY_PRESSED},   // X
	{{0,0}, EV_KEY, 0x002d, KEY_RELEASED},
};

static const char *event_label(int value) {
	switch (value) {
		case KEY_PRESSED: return "PRESSED";
		case KEY_RELEASED: return "RELEASED";
		case KEY_REPEAT: return "REPEATED";
		default: return "UNKNOWN";
	}
}

static void dump_event(const input_event_sim *ev) {
	printf("%-8s 0x%04x (%3u)\n", event_label(ev->value), ev->code, ev->code);
}

int main(void) {
	puts("Simulated keyboard monitor (press E+X to exit)");
	for (size_t i = 0; i < sizeof(events)/sizeof(events[0]); i++) {
		dump_event(&events[i]);
	}
	puts("\nNote: Real labs read from /dev/input/... using struct input_event.");
	puts("Run this binary as a preview before going root on actual hardware.");
	return 0;
}



#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static void usage(const char *prog) {
	fprintf(stderr,
	        "Usage: %s <mode> [args]\n"
	        "Modes:\n"
	        "  ioports <path>    - parse /proc/ioports style file\n"
	        "  keyboard <device> - read struct input_event from device/capture\n"
	        "  shortcuts <file>  - detect combos from recorded events\n",
	        prog);
}

/* TODO 1: read /proc/ioports style text and print dma1/pic1/timer0 info.
 * Hints:
 *   - use fgets to iterate lines
 *   - match prefix via strstr()
 *   - print range + description
 */
static int mode_ioports(const char *path) {
	(void)path;
	fprintf(stderr, "[TODO] Implement mode_ioports()\n");
	return 1;
}

/* TODO 2: open the keyboard device (requires sudo) and read struct input_event.
 * Hints:
 *   - struct input_event is defined in <linux/input.h> on Linux
 *   - repeatedly read sizeof(struct input_event) bytes and dump code/type/value
 *   - exit when user presses E+X combo (like slides)
 */
static int mode_keyboard(const char *device) {
	(void)device;
	fprintf(stderr, "[TODO] Implement mode_keyboard()\n");
	return 1;
}

/* TODO 3: detect shortcuts from saved events (binary file of input_event).
 * Hints:
 *   - maintain a set of currently pressed key codes
 *   - on press, check combos (P+E, C+A+P, custom)
 *   - print messages plus underlying events
 */
static int mode_shortcuts(const char *file) {
	(void)file;
	fprintf(stderr, "[TODO] Implement mode_shortcuts()\n");
	return 1;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		usage(argv[0]);
		return 1;
	}
	if (strcmp(argv[1], "ioports") == 0) {
		if (argc != 3) { usage(argv[0]); return 1; }
		return mode_ioports(argv[2]);
	} else if (strcmp(argv[1], "keyboard") == 0) {
		if (argc != 3) { usage(argv[0]); return 1; }
		return mode_keyboard(argv[2]);
	} else if (strcmp(argv[1], "shortcuts") == 0) {
		if (argc != 3) { usage(argv[0]); return 1; }
		return mode_shortcuts(argv[2]);
	}
	usage(argv[0]);
	return 1;
}



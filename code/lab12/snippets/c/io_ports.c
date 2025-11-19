#include <stdio.h>
#include <string.h>

typedef struct {
	const char *range;
	const char *label;
	const char *description;
} io_port;

static const io_port sample_ports[] = {
	{ "0000-001f", "dma1",    "8237A DMA controller #1" },
	{ "0020-0021", "pic1",    "8259A Programmable Interrupt Controller" },
	{ "0040-0043", "timer0",  "8254 Programmable Interval Timer" },
	{ "0060-0060", "keyboard","8042 keyboard controller data port" },
	{ "0064-0064", "kbd_cmd","8042 keyboard controller command port" },
	{ "00a0-00a1", "pic2",    "Secondary PIC" },
	{ "00c0-00df", "dma2",    "8237A DMA controller #2" },
	{ "03f8-03ff", "ttyS0",   "Legacy serial port COM1" },
};

static void print_table(void) {
	puts("=== Sample /proc/ioports snapshot ===");
	for (size_t i = 0; i < sizeof(sample_ports)/sizeof(sample_ports[0]); i++) {
		printf("%-10s %-8s %s\n",
		       sample_ports[i].range,
		       sample_ports[i].label,
		       sample_ports[i].description);
	}
}

static void explain(const char *label) {
	for (size_t i = 0; i < sizeof(sample_ports)/sizeof(sample_ports[0]); i++) {
		if (strcmp(sample_ports[i].label, label) == 0) {
			printf("\n[%s] %s spans %s\n",
			       sample_ports[i].label,
			       sample_ports[i].description,
			       sample_ports[i].range);
			if (strcmp(label, "dma1") == 0) {
				puts("  → Channels 0-3 for low-memory DMA transfers.");
			} else if (strcmp(label, "pic1") == 0) {
				puts("  → Routes hardware IRQs 0-7 to the CPU.");
			} else if (strcmp(label, "timer0") == 0) {
				puts("  → Provides periodic interrupts via PIT channel 0.");
			}
			return;
		}
	}
	printf("Label %s not found in sample data.\n", label);
}

int main(void) {
	print_table();
	explain("dma1");
	explain("pic1");
	explain("timer0");
	puts("\nTip: run `sudo cat /proc/ioports` on Linux to inspect the live system.");
	return 0;
}



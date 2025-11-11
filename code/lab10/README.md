Lab 10: Disk Scheduling Algorithms

Overview
- Simulations of disk head scheduling: FCFS, SSTF, SCAN, C-SCAN, LOOK
- Demonstrates total head movement and service order for a fixed request queue
- Highlights trade-offs: throughput vs fairness and starvation risks

Snippets

fcfs_disk.c - First-Come-First-Served
sstf_disk.c - Shortest Seek Time First
scan_disk.c - SCAN (Elevator)
cscan_disk.c - C-SCAN (Circular SCAN)
look_disk.c - LOOK (bounds by last requests)
compare_all.c - Side-by-side comparison of all algorithms

Build: `make`
Run: `./bin/<demo>`

Notes: Cylinder range assumed [0..199]; initial head at 50 by default in demos.



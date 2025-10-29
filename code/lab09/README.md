Lab 09: Page Replacement Algorithms

Overview
- Page replacement algorithm simulations: FIFO, LRU, Optimal
- Demonstrates page faults, hits, and performance comparison
- Shows Belady's Anomaly in FIFO

Snippets

fifo_paging.c - First-In-First-Out page replacement
lru_paging.c - Least Recently Used page replacement  
optimal_paging.c - Optimal (Belady's) algorithm
compare_all.c - Side-by-side comparison of all algorithms

Build: `make`
Run: `./bin/<demo>`

Comparison: FIFO (simple, Belady's Anomaly) vs LRU (practical, better performance) vs Optimal (theoretical minimum, requires future knowledge)


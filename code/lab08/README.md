Lab 08: Virtual Memory

Overview
- Virtual memory management concepts including address translation, paging, page tables, page faults, and memory mapping.
- Demonstrations of /proc filesystem, mmap(), demand paging, and copy-on-write mechanisms.

Snippets

page_calc.c - Virtual address calculation and page/frame translation
proc_maps.c - Process memory mappings via /proc/[pid]/maps
page_fault_demo.c - Page faults, demand paging, copy-on-write
mmap_demo.c - Memory mapping (anonymous, shared, file-backed)

Build: `make`
Run: `./snippets/sh/run_<demo>.sh`


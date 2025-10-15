Lab 07: Memory Management

Overview
- This lab demonstrates memory management concepts in C including memory layout, pointers, dynamic allocation, and memory allocator algorithms.
- Contains educational C demos with shell helpers to illustrate program memory segments, pointer operations, malloc/free usage, and allocation strategies (First Fit, Best Fit, Worst Fit).
- All allocator demos are simulations to understand OS-level memory management principles.

Snippets overview (what / definition / why)

Memory Fundamentals:

memory_layout.c
  - What: Visualizes the memory layout of a C program showing all major segments and their addresses.
  - Definition: A C program's memory is divided into segments: Text (code), Data (initialized globals), BSS (uninitialized globals), Heap (dynamic allocation), and Stack (local variables). Each segment serves a specific purpose and grows in different directions.
  - Why: Understand where different types of data are stored; learn memory organization; visualize stack vs heap; see how addresses relate to memory segments; foundation for debugging memory issues.

pointer_basics.c
  - What: Demonstrates pointer fundamentals including declaration, dereferencing, arithmetic, and pass-by-reference.
  - Definition: A pointer is a variable that stores a memory address. The & operator gets an address, * dereferences (accesses value at address). Pointer arithmetic moves by sizeof(type) bytes. Pass-by-reference allows functions to modify caller's variables.
  - Why: Master essential pointer concepts; understand the relationship between pointers and arrays; learn why C uses pointers for efficiency; practice passing addresses to functions; foundation for dynamic memory.

dynamic_allocation.c
  - What: Showcases dynamic memory allocation using malloc(), calloc(), realloc(), and proper deallocation with free().
  - Definition: malloc(size) allocates uninitialized memory; calloc(n, size) allocates zero-initialized memory; realloc(ptr, size) resizes allocation; free(ptr) releases memory. All operate on the heap and require manual management.
  - Why: Learn heap allocation vs stack; understand initialization differences (malloc vs calloc); practice resizing with realloc; master memory leak prevention; see proper allocation/deallocation patterns.

brk_sbrk_demo.c
  - What: Demonstrates low-level heap management using brk() and sbrk() system calls to control the program break.
  - Definition: The program break marks the end of the heap segment. sbrk(0) returns current break; sbrk(n) increases heap by n bytes; brk(addr) sets break to address. Historical mechanisms predating modern virtual memory.
  - Why: Understand how malloc works internally; learn historical heap management; see the relationship between user-space allocators and OS; compare with modern mmap-based allocation.

Memory Allocator Simulations:

allocator_firstfit.c
  - What: Simulates First Fit allocation strategy - searches from beginning and uses first suitable free block.
  - Definition: First Fit traverses the free list from the start and allocates in the first block that meets the size requirement. Stops searching immediately upon finding a fit. Non-optimal but fast.
  - Why: Understand the simplest allocation strategy; observe speed vs fragmentation tradeoff; see how early allocations affect later ones; learn why fragments accumulate at memory start.

allocator_bestfit.c
  - What: Simulates Best Fit allocation strategy - finds the smallest free block that satisfies the request.
  - Definition: Best Fit searches the entire free list to find the block with minimum waste (closest fit to requested size). Minimizes space loss per allocation but may create many tiny fragments.
  - Why: Learn optimal allocation for memory utilization; understand the cost of full list traversal; observe tiny fragment creation; compare performance with First Fit; see when precision matters.

allocator_worstfit.c
  - What: Simulates Worst Fit allocation strategy - allocates from the largest available free block.
  - Definition: Worst Fit searches for the maximum-sized free block and allocates from it, leaving a large remainder. Goal is to keep fragments usable, but often performs poorly in practice.
  - Why: Understand the counterintuitive worst-fit approach; see why leaving large fragments doesn't always help; compare performance with other strategies; learn when it might be useful (rarely).

What to show in lecture
- Memory layout: Run memory_layout and use `size` command to show segment sizes; demonstrate with `cat /proc/<pid>/maps`.
- Pointers: Show pointer_basics explaining &, *, and pointer arithmetic; demonstrate pass-by-reference.
- Dynamic allocation: Compare malloc (uninitialized) vs calloc (zeroed); show realloc preserving data; emphasize free() importance.
- brk/sbrk: Demonstrate program break movement; explain historical context; compare with modern malloc/mmap.
- Allocator comparison: Run all three allocators with same operations; compare throughput and fragmentation; discuss real-world usage.

Memory Segments
- Text (Code): Machine code, read-only, shared across processes
- Data: Initialized global/static variables
- BSS: Uninitialized global/static (zeroed at start)
- Heap: Dynamic allocation (grows upward ↑)
- Stack: Local variables, function calls (grows downward ↓)
- Command-line args & environment: At top of memory

Build
- Compile all demos: `make` (or `./compile_all.sh`)
- Compile fundamentals only: `make fundamentals`
- Compile allocators only: `make allocators`
- Binaries are placed in `bin/` directory

Run quickly (scripts)
Memory fundamentals:
- Memory layout: `./snippets/sh/run_memory_layout.sh`
- Pointer basics: `./snippets/sh/run_pointer_basics.sh`
- Dynamic allocation: `./snippets/sh/run_dynamic_allocation.sh`
- brk/sbrk demo: `./snippets/sh/run_brk_sbrk_demo.sh`

Memory allocators:
- First Fit: `./snippets/sh/run_allocator_firstfit.sh`
- Best Fit: `./snippets/sh/run_allocator_bestfit.sh`
- Worst Fit: `./snippets/sh/run_allocator_worstfit.sh`

Run all demos: `./present_all.sh`

Key concepts covered
- Memory segments: text, data, bss, heap, stack
- Pointers: addresses, dereferencing, arithmetic, pass-by-reference
- Dynamic allocation: malloc, calloc, realloc, free
- Memory management: program break, brk/sbrk, mmap
- Allocation strategies: First Fit, Best Fit, Worst Fit
- Fragmentation: internal vs external
- Memory leaks and proper deallocation
- Alignment and memory blocks

Allocation Strategy Comparison
First Fit:
  - Speed: Fast (stops at first fit) ⚡
  - Memory use: Poor (fragments at start)
  - Best for: Speed-critical, small allocations

Best Fit:
  - Speed: Slow (full search required) 🐌
  - Memory use: Good (minimal waste per block)
  - Best for: Memory-constrained systems

Worst Fit:
  - Speed: Slow (full search required) 🐌
  - Memory use: Poor (breaks up large blocks)
  - Best for: Rarely useful in practice

Notes for observing
- Use `size <binary>` to see text/data/bss segment sizes
- Use `cat /proc/<pid>/maps` to see runtime memory mappings (Linux)
- Use `vmmap <pid>` on macOS for memory map
- Memory addresses will differ between runs (ASLR - Address Space Layout Randomization)
- Allocator demos show simplified versions; real allocators are more complex
- Memory leak detection: `valgrind` (Linux) or `leaks` (macOS)
- Stack grows downward (high to low addresses)
- Heap grows upward (low to high addresses)

Common Memory Issues
- Memory leak: Allocated but never freed
- Double free: Calling free() twice on same pointer
- Use after free: Using pointer after free()
- Buffer overflow: Writing beyond allocated bounds
- Uninitialized memory: Using malloc'd memory before setting values
- Stack overflow: Excessive recursion or large local arrays

Dynamic Allocation Best Practices
1. Always check if allocation succeeded (ptr != NULL)
2. Free allocated memory when done
3. Set pointer to NULL after free
4. Don't use pointer after free
5. Match every malloc/calloc with free
6. Use calloc when zero-initialization is needed
7. Use realloc for resizing, not manual copy
8. Consider alignment requirements

Safety
- All programs are educational demonstrations
- Allocator simulations use fixed-size arrays (safe)
- Memory operations are bounded and checked
- No system-level changes or persistent effects
- Use Ctrl+C to interrupt any running demo




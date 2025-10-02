Lab 05: Interprocess Communication (IPC) and POSIX Threads

Overview
- This lab demonstrates IPC mechanisms (pipes and named pipes) and POSIX threads programming concepts including thread creation, synchronization, and the critical section problem.
- Contains minimal C demos with shell helpers to illustrate pipes, FIFOs, thread creation, race conditions, mutexes, and thread joining.
- Compatible with both Linux and macOS.

Snippets overview (what / definition / why)

pipe_demo.c
  - What: Demonstrates unnamed pipe creation with `pipe()` syscall for parent-child communication.
  - Definition: A pipe is a unidirectional (half-duplex) IPC mechanism with a read end (fd[0]) and write end (fd[1]). Data written to write end can be read from read end. Pipes exist only while the creating process is alive.
  - Why: Learn the fundamental Unix IPC primitive; understand file descriptors, fork/exec with pipes, and one-way communication between related processes.

named_pipe_demo.c
  - What: Creates a named pipe (FIFO) using `mkfifo()` for process communication via filesystem.
  - Definition: A named pipe (FIFO) is a special file that persists in the filesystem beyond process lifetime, enabling IPC between unrelated processes. Follows FIFO semantics.
  - Why: Understand persistent IPC mechanisms; see how filesystem-based IPC differs from anonymous pipes; learn about blocking on open() until both reader and writer are ready.

thread_create.c
  - What: Creates multiple POSIX threads using `pthread_create()` and waits for completion with `pthread_join()`.
  - Definition: POSIX threads (pthreads) are lightweight execution contexts within a single process that share the same address space and resources. `pthread_create()` spawns new threads; `pthread_join()` blocks until a thread terminates.
  - Why: Learn basic thread lifecycle management; understand thread IDs (`pthread_t`); observe concurrent execution within a single process.

race_condition.c
  - What: Demonstrates a classic race condition where multiple threads increment a shared counter without synchronization.
  - Definition: A race condition occurs when multiple threads access shared data concurrently without proper synchronization, and the outcome depends on unpredictable thread scheduling. The critical section is code that accesses shared resources and must not be executed by multiple threads simultaneously.
  - Why: Visualize the critical section problem; understand why `counter++` is not atomic; observe non-deterministic and incorrect results; motivate the need for synchronization.

mutex_demo.c
  - What: Solves the race condition using a mutex (`pthread_mutex_t`) to protect the critical section.
  - Definition: A mutex (mutual exclusion lock) ensures only one thread can access a critical section at a time. `pthread_mutex_lock()` acquires the lock (blocks if held by another thread); `pthread_mutex_unlock()` releases it.
  - Why: Learn the primary synchronization primitive for preventing race conditions; understand mutual exclusion; compare results with unsynchronized version to see correctness.

thread_join_demo.c
  - What: Demonstrates `pthread_join()` usage for waiting on thread completion and retrieving return values.
  - Definition: `pthread_join()` blocks the calling thread until the specified thread terminates, optionally retrieving the thread's return value (via `void*` pointer). Essential for thread cleanup and result collection.
  - Why: Understand thread synchronization beyond mutexes; learn how main thread coordinates with worker threads; practice passing data back from threads.

What to show in lecture
- Pipes vs Named Pipes: Show `pipe()` for parent-child communication and `mkfifo()` for unrelated processes.
- Thread creation: Demonstrate `pthread_create()`, thread IDs, and shared address space.
- Race condition: Run `race_condition` multiple times to show non-deterministic results and explain the critical section.
- Mutex protection: Compare `race_condition` vs `mutex_demo` to show how mutexes guarantee correctness.
- Thread joining: Show how `pthread_join()` synchronizes thread completion and retrieves results.

Build
- Compile all demos: `make` (or `./compile_all.sh`)
- Binaries are placed in `bin/` directory.
- Thread programs require `-pthread` flag (handled by Makefile).

Run quickly (scripts)
- Pipe demo: `./snippets/sh/run_pipe_demo.sh "Your message"`
- Named pipe demo: `./snippets/sh/run_named_pipe_demo.sh "Your message"`
- Thread creation: `./snippets/sh/run_thread_create.sh`
- Race condition: `./snippets/sh/run_race_condition.sh`
- Mutex demo: `./snippets/sh/run_mutex_demo.sh`
- Thread join demo: `./snippets/sh/run_thread_join_demo.sh`
- Run all demos: `./present_all.sh`

Key concepts covered
- IPC mechanisms: unnamed pipes (pipe), named pipes (mkfifo/FIFO)
- File descriptors and half-duplex communication
- POSIX threads: pthread_create, pthread_join, pthread_exit
- Thread synchronization: mutexes (pthread_mutex_t)
- Critical section problem and race conditions
- Mutual exclusion and thread-safe programming

Notes for observing
- Race condition results vary between runs due to non-deterministic thread scheduling.
- Mutex demo should always produce correct results (verify counter matches expected value).
- On Linux, use `ps -eL` to show threads; on macOS, use `ps -M -p <PID>`.
- Named pipes appear as special files: `ls -l /tmp/demo_fifo` shows `p` file type.
- Use `Ctrl+C` to interrupt programs if needed.

Safety
- All programs are minimal and self-contained.
- Named pipe demo cleans up `/tmp/demo_fifo` automatically.
- No daemonization; safe to run from terminal.




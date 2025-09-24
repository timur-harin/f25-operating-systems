Lab 04: Processes and Threads (Linux and macOS)

Overview
- This lab contains short, minimal C demos and small shell helpers to illustrate key OS concepts: process tree, fork/exec, zombie and orphan processes, basic threads, and a simple process state “simulator”.
- Scripts and notes include Linux and macOS variants. For best visuals, install `pstree`.

What to show in lecture
- pstree visualization: options `-p`, `-a`, `-h`, `-g` to highlight PID, args, current process, and groups.
- Zombie and orphan processes: run tiny C demos and observe in `top`, `ps`, and `pstree`.
- Process state transitions: stepwise simulator prints Ready/Running/Blocked cycles.
- Process vs thread and cores vs threads: show counters and thread listing (`ps -eL` on Linux, `ps -M` on macOS).

Install helpers
- Linux (Debian/Ubuntu): `sudo apt-get update && sudo apt-get install -y pstree` (in package `psmisc`).
- macOS (Homebrew): `brew install pstree`.

Build
- Make sure you have a C compiler (Clang or GCC). Then:
  - Build everything: `make -C code/lab04`
  - Or from this folder: `make`
  - Binaries go to `code/lab04/bin/`.

Run quickly (scripts)
- Show pstree usage: `code/lab04/snippets/sh/pstree_demo.sh`
- Zombie demo: `code/lab04/snippets/sh/run_zombie.sh`
- Orphan demo: `code/lab04/snippets/sh/run_orphan.sh`
- Fork+exec demo: `code/lab04/snippets/sh/run_fork_exec.sh`
- Threads demo: `code/lab04/snippets/sh/run_threads.sh`
- State simulator: `code/lab04/snippets/sh/run_state_sim.sh`

Notes for observing
- Linux process tree alternative if `pstree` unavailable:
  - `ps -e --forest -o pid,ppid,pgid,tty,stat,cmd`
- macOS process list (no tree by default):
  - `ps -Ao pid,ppid,pgid,tty,state,command`
  - Install `pstree` via Homebrew for tree view.
- Show threads:
  - Linux: `ps -eL -o pid,tid,stat,cmd | grep <PID>`
  - macOS: `ps -M -p <PID>` (or `top -H` for a live view)

Safety
- These programs are minimal and do not daemonize; run from a terminal. Use `Ctrl+C` to stop if needed.



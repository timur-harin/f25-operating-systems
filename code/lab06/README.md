Lab 06: Process Scheduling and Signals

Overview
- This lab demonstrates Unix signals for interprocess communication and process control, plus CPU scheduling algorithm simulations.
- Contains minimal C demos with shell helpers to illustrate signal handling (SIGINT, SIGTERM, SIGALRM, SIGUSR), and scheduling algorithms (FCFS, SJF, Round Robin).
- All demos are educational simulations to understand OS scheduling concepts and signal mechanisms.

Snippets overview (what / definition / why)

Signal Demos:

basic_signals.c
  - What: Demonstrates an infinite loop program that can be terminated using different signals (SIGINT, SIGQUIT, SIGTERM).
  - Definition: Signals are software interrupts delivered to processes to notify them of events. SIGINT (Ctrl+C) requests termination, SIGQUIT (Ctrl+\) quits with core dump, SIGTERM is a polite termination request, and SIGKILL forces termination.
  - Why: Learn the standard signals for process control; understand default signal actions; see how processes respond to user interrupts and kill commands.

signal_handler.c
  - What: Registers a custom signal handler for SIGINT that catches the first interrupt and restores default behavior for the second.
  - Definition: signal() function registers a handler function that executes when a specific signal is received. Handlers can perform custom actions, ignore signals, or restore default behavior (SIG_DFL).
  - Why: Understand how to override default signal behavior; learn signal handler registration; practice graceful shutdown and state cleanup before termination.

alarm_demo.c
  - What: Uses alarm() syscall to set a timer that sends SIGALRM to a child process after a specified duration.
  - Definition: alarm(N) schedules SIGALRM delivery after N seconds. The signal can be caught with a handler for timeout operations, periodic tasks, or watchdog timers.
  - Why: Learn time-based signals; understand how to implement timeouts; see parent-child coordination with alarms; practice handling asynchronous events.

sigusr_demo.c
  - What: Demonstrates user-defined signals (SIGUSR1, SIGUSR2) for custom application-level IPC and error handling.
  - Definition: SIGUSR1 and SIGUSR2 are reserved for user-defined purposes. Programs can raise() these signals to themselves or send them to other processes for custom notifications.
  - Why: Learn application-specific signal usage; understand raise() for self-signaling; practice custom error handling and validation with signals.

Scheduling Algorithm Demos:

fcfs_scheduler.c
  - What: Simulates First Come First Served (FCFS) scheduling algorithm with process metrics calculation.
  - Definition: FCFS is a non-preemptive scheduling algorithm that executes processes in arrival order. Once a process starts, it runs to completion. Formula: WT = TAT - BT, TAT = CT - AT.
  - Why: Understand the simplest scheduling algorithm; observe convoy effect (long processes blocking short ones); calculate waiting time, turnaround time, and completion time metrics.

sjf_scheduler.c
  - What: Simulates Shortest Job First (SJF) scheduling, selecting the process with shortest burst time among arrived processes.
  - Definition: SJF is non-preemptive and selects the ready process with minimum burst time. Provides optimal (minimum) average waiting time but may cause starvation of longer processes.
  - Why: Learn optimal scheduling for minimizing wait time; understand the tradeoff between fairness and efficiency; see how execution order differs from arrival order.

rr_scheduler.c
  - What: Simulates Round Robin (RR) scheduling with configurable time quantum, showing preemptive time-sharing behavior.
  - Definition: RR is preemptive; each process gets a fixed time quantum. After quantum expires, the process moves to the back of the ready queue. Provides fair CPU allocation and good response time.
  - Why: Understand preemptive scheduling and context switching; observe impact of time quantum on performance; learn time-sharing systems behavior; compare with FCFS when quantum is large.

What to show in lecture
- Signal basics: Run basic_signals and demonstrate Ctrl+C (SIGINT), Ctrl+\ (SIGQUIT), and kill command variants.
- Signal handlers: Show signal_handler catching first SIGINT, then allowing second to terminate.
- Alarm timers: Demonstrate alarm_demo with 3-second timer interrupting a 5-second loop.
- Custom signals: Use sigusr_demo to show SIGUSR1/SIGUSR2 for input validation.
- FCFS vs SJF: Compare execution order and average waiting times to show SJF optimality.
- Round Robin: Run rr_scheduler with different time quanta (2, 4, 8) to show impact on fairness and response time.
- Scheduling metrics: Explain formulas for WT, TAT, CT, RT and their significance.

Scheduling Terminology
- Burst Time (BT): Total CPU time needed by process
- Arrival Time (AT): When process enters ready queue
- Completion Time (CT): When process finishes execution
- Turnaround Time (TAT): Total time from arrival to completion (TAT = CT - AT)
- Waiting Time (WT): Time spent in ready queue (WT = TAT - BT)
- Response Time (RT): Time from arrival to first CPU allocation (RT only for preemptive)

Build
- Compile all demos: `make` (or `./compile_all.sh`)
- Compile only signals: `make signals`
- Compile only schedulers: `make schedulers`
- Binaries are placed in `bin/` directory

Run quickly (scripts)
Signal demos:
- Basic signals: `./snippets/sh/run_basic_signals.sh`
- Signal handler: `./snippets/sh/run_signal_handler.sh`
- Alarm demo: `./snippets/sh/run_alarm_demo.sh`
- SIGUSR demo: `./snippets/sh/run_sigusr_demo.sh`

Scheduling demos:
- FCFS: `./snippets/sh/run_fcfs_scheduler.sh`
- SJF: `./snippets/sh/run_sjf_scheduler.sh`
- Round Robin: `./snippets/sh/run_rr_scheduler.sh`

Run all demos: `./present_all.sh`

Key concepts covered
- Unix signals: SIGINT, SIGQUIT, SIGTERM, SIGKILL, SIGALRM, SIGUSR1, SIGUSR2
- Signal handling: signal(), raise(), kill(), alarm()
- Signal actions: SIG_DFL, SIG_IGN, custom handlers
- CPU scheduling: FCFS, SJF, Round Robin
- Preemptive vs non-preemptive scheduling
- Scheduling metrics: AT, BT, CT, WT, TAT, RT
- Time quantum and context switching
- Convoy effect and starvation

Notes for observing
- Signal demos may require user interaction (Ctrl+C, input)
- Use `timeout` command in scripts to auto-terminate infinite loops
- Core dumps from SIGQUIT may require `ulimit -c unlimited`
- Scheduler demos are simulations, not real OS scheduling
- Compare FCFS, SJF, and RR outputs to understand algorithm differences
- Try different time quanta in Round Robin to see behavior changes
- Process metrics help understand scheduling algorithm efficiency

Common signals reference
- SIGINT (2): Interactive interrupt (Ctrl+C), can be caught
- SIGQUIT (3): Quit with core dump (Ctrl+\), can be caught
- SIGKILL (9): Force kill, cannot be caught or ignored
- SIGTERM (15): Polite termination request, can be caught
- SIGALRM (14): Alarm clock timer expiration
- SIGUSR1 (10): User-defined signal 1
- SIGUSR2 (12): User-defined signal 2
- SIGSTOP (19): Stop process, cannot be caught
- SIGCONT (18): Continue stopped process

Safety
- All programs are minimal and self-contained
- Signal demos run in foreground or use timeout
- Scheduler simulations are computations, not real process control
- Use Ctrl+C to interrupt any running demo
- No system-level changes or persistent effects




Lab 13 Livecoding: Deadlock Workshop
====================================

Goal
----
Practice building wait-for graphs, detecting cycles, and replaying resource requests as described in the lab.

How to use
----------
1. Open `deadlock_workshop.c`.
2. Complete the `TODO` sections:
   - Build a graph from `thread resource` logs.
   - Run a DFS/BFS to find cycles (deadlocks).
   - Simulate recovery by unlocking or killing a victim thread.
3. Build with `make`.
4. Run helpers:
   - `./deadlock_workshop graph sample.txt`
   - `./deadlock_workshop detect sample.txt`
   - `./deadlock_workshop recover sample.txt`

Stretch ideas
-------------
- Implement the Banker's algorithm to test safe states.
- Emit Graphviz `.dot` files for visualizing wait-for graphs.
- Add a log replay speed toggle to mimic real-time tracing.



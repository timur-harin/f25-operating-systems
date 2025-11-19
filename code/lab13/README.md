Lab 13: Deadlocks & Resource Allocation

Overview
- Review Coffman conditions and resource-allocation graphs
- Simulate deadlock creation with threads and mutexes
- Implement simple detection and request processing logic inspired by slides

Snippets

deadlock_sim.c - Two-thread deadlock plus watchdog detector
wait_for_graph.c - Build a wait-for graph and detect cycles via DFS
request_processor.c - Replay `thread resource` requests and report potential deadlocks

Build: `make`
Run: `./bin/<demo>`

Notes: Programs avoid real kernel resources but print the same state summaries you would capture in the full lab.



Lab 11: Alternative File Systems

Overview
- Simulations illustrating alternative FS designs and strategies
- Log-structured filesystem (LFS) concepts, journaling, and copy-on-write (CoW) trees
- Focuses on algorithms and state transitions rather than kernel integration

Snippets

lfs_log.c - Append-only log, segment utilization, and simple cleaner
journaling_demo.c - Write-ahead logging, commit records, and recovery sketch
cow_tree.c - Copy-on-write tree with snapshotting semantics

Build: `make`
Run: `./bin/<demo>`

Notes: Educational simulations run in user space; outputs show structure transitions and durability points.



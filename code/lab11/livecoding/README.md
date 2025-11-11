Lab 11 Livecoding: Alternative File Systems
===========================================

Goal
----
Hands-on simulations to understand LFS, journaling, and copy-on-write (CoW) trees.

How to use
----------
1. Open `alt_fs_workshop.c`.
2. Work through the `TODO` markers (three sections align with lecture topics).
3. Build with: `make`
4. Run: `./alt_fs_workshop [command]`
   - `lfs`        : append-only log + simple cleaner
   - `journal`    : write-ahead logging + recovery sketch
   - `cow`        : copy-on-write tree and snapshots

Stretch ideas
-------------
- Add segment utilization and cost model to `lfs`.
- Add multi-op transactions and crash points to `journal`.
- Add reference counting and deduplication to `cow`.



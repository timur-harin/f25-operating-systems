Lab 10 Livecoding: Filesystem & I/O Practice
============================================

Goal
----
Hands-on exercises to explore UNIX filesystem APIs and connect them with Lab 10 concepts.

How to use
----------
1. Open `fs_workshop.c`.
2. Work through the `TODO` markers (there are five sections aligning with the lecture topics).
3. Build with: `make`
4. Run: `./fs_workshop [command] [args]`
   - `list <path>`: directory traversal
   - `stat <path>`: inode metadata
   - `io-demo`: open/write/fsync example
   - `sparse`: create sparse file
   - `mmap-copy <src> <dst>`: memory-mapped copy

Stretch ideas
-------------
- Add error handling wrappers to reduce duplication.
- Extend `list` to show inode numbers and file types similar to `ls -li`.
- Record timestamps (atime/mtime) before and after operations to observe changes.
- Add checksum verification for `mmap-copy`.



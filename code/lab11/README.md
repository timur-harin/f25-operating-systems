Lab 11: Filesystems and UNIX I/O

Overview
- Practical UNIX filesystem and file I/O demonstrations
- Directory traversal, file metadata (inode), sparse files, mmap, and robust I/O
- Connects API usage to filesystem concepts from the lecture

Snippets

list_dir.c - Traverse a directory with opendir/readdir and stat
inode_info.c - Display POSIX stat() fields and permissions
file_io.c - Write/read with open/read/write/fsync and O flags
sparse_file.c - Create and inspect sparse files with lseek(SEEK_CUR/SEEK_END)
mmap_copy.c - Copy a file using mmap for zero-copy I/O

Build: `make`
Run: `./bin/<demo>`

Notes: Demos use a temp working directory under ./bin when needed; run scripts provided.



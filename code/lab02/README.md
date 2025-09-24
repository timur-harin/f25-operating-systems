## Lab 02 — Interactive Snippets (OS)

This folder contains small, useful code snippets and scripts aligned with the Lab 2 slides. Start with the terminal commands cheatsheet, then explore C snippets connected to the slide topics and exercises.

Slides text: `slides_lab02.txt`

### Terminal commands cheatsheet

- **Navigation**
  - `pwd` — print current directory
  - `ls -la` — list all files with details
  - `cd path` — change directory; `cd -` — previous dir; `cd ~` — home
- **Files & folders**
  - `mkdir name` — create folder; `mkdir -p a/b/c`
  - `touch file` — create empty file; `cp src dst` — copy; `mv src dst` — move/rename; `rm file`; `rm -r dir`
  - `cat file` — print; `less file` — page; `head -n 20 file`; `tail -n 20 file`; `wc -l file`
- **Search**
  - `grep -R "pattern" .` — recursive search; `grep -n pattern file` — show line numbers
  - `find . -name "*.c"` — find by name; `rg pattern` — fast search (ripgrep)
- **Redirection & piping**
  - `cmd > out.txt` — overwrite; `cmd >> out.txt` — append
  - `cmd 2> err.txt` — stderr; `cmd &> all.txt` — stdout+stderr
  - `cmd1 | cmd2` — pipe; `cmd | tee file` — view and save
- **Processes & jobs**
  - `cmd &` — run in background; `jobs` — list jobs; `fg %1` — foreground; `bg %1` — background
  - `ps aux | grep name` — list processes; `kill -TERM PID`; `kill -9 PID`
  - `time cmd` — measure; `top` / `htop` — monitor
- **Permissions & links**
  - `chmod +x script.sh` — make executable; `chmod 644 file`
  - `ln -s target linkname` — symlink
- **Networking**
  - `curl -I https://example.com` — headers; `curl -o file URL` — download
  - `lsof -i :PORT` — which process listens; `ping host` — reachability
- **Environment & shell**
  - `echo $PATH`; `export VAR=value`; `env` — list env
  - `alias gs='git status'`; `unalias gs`
  - History: `history`, `!!` — last command, `!-2` — 2nd last
- **Compilation (C)**
  - `gcc file.c -o app` — build and link
  - `gcc -E file.c -o file.i` — preprocess only
  - `gcc -S file.c -o file.s` — compile to assembly
  - `gcc -c file.c -o file.o` — compile to object

### How to use

1) Ensure you are in this directory:
```bash
cd code/lab02
```
2) Run any script in `snippets/sh` to compile and execute the corresponding snippet.

3) Full compilation stages for a simple program in this folder:
```bash
./compile_main.sh
./main.out
```

### Snippets index (linked to slides)

- **Hello World (slide ~10)** — `snippets/c/hello_world.c` — minimal C program
- **Compilation stages (slides ~11–12)** — `snippets/sh/compile_stages.sh` — preprocess, compile, assemble, link
  - Or use folder-level example: `main.c` with `./compile_main.sh`
- **Datatypes & sizes (slide ~13) — Exercise 1**
  - C: `snippets/c/datatypes_sizes_ex1.c`
  - Run: `snippets/sh/ex1.sh`
- **I/O basics (slides ~14–15)** — `snippets/c/io_basics.c`
- **Control statements (slide ~16)** — `snippets/c/control_flow.c`
- **Reverse until dot (Exercise 2)**
  - C: `snippets/c/reverse_until_dot_ex2.c`
  - Run: `snippets/sh/ex2.sh`
- **Base conversion (Exercise 3)**
  - C: `snippets/c/convert_base_ex3.c`
  - Run: `snippets/sh/ex3.sh`
- **Count characters (Exercise 4)**
  - C: `snippets/c/count_chars_ex4.c`
  - Run: `snippets/sh/ex4.sh`
- **Tribonacci (Exercise 5)**

### Quick runs

From `code/lab02/snippets`:
```bash
# Hello World
gcc -std=c11 -O2 c/hello_world.c -o hello && ./hello

# Compilation stages demo (use any .c file path)
sh/compile_stages.sh c/hello_world.c

# Exercises
sh/ex1.sh
sh/ex2.sh
sh/ex3.sh
sh/ex4.sh
sh/ex5.sh
```
  - C: `snippets/c/tribonacci_ex5.c`
  - Run: `snippets/sh/ex5.sh`

Tip: See `slides_lab02.txt` for the extracted text to correlate topics and tasks.



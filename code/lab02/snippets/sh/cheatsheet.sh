#!/usr/bin/env bash
set -euo pipefail

# This script demonstrates common shell commands safely.
# It creates a temporary playground and cleans up afterward.

PLAYDIR=$(mktemp -d -t lab02_cheatsheet.XXXXXX)
cleanup() { rm -rf "$PLAYDIR"; }
trap cleanup EXIT

echo "Playground: $PLAYDIR"
cd "$PLAYDIR"

echo
echo "== Navigation =="
pwd
mkdir -p a/b/c
ls -la
cd a
cd - >/dev/null
cd ~ >/dev/null
cd "$PLAYDIR"

echo
echo "== Files & folders =="
mkdir name && echo "created dir 'name'"
mkdir -p a/b/c && echo "created a/b/c"
touch file1.txt && echo "hello" > file1.txt
cp file1.txt file2.txt
mv file2.txt file_renamed.txt
cat file1.txt
head -n 1 file1.txt
tail -n 1 file1.txt
wc -l file1.txt
echo "line1" > big.txt; seq 2 30 >> big.txt
less +G big.txt | cat
rm file1.txt
rm -r name

echo
echo "== Search =="
echo -e "alpha\nbeta\ngamma" > words.txt
grep -n beta words.txt
grep -R "alpha" .
find . -name "*.txt" | cat
command -v rg >/dev/null 2>&1 && rg alpha || echo "rg not installed, skipping"

echo
echo "== Redirection & piping =="
echo "content A" > out.txt
echo "content B" >> out.txt
bash -c 'echo stdout; echo stderr 1>&2' 1>stdout.txt 2>err.txt || true
bash -c 'echo both stdout; echo both stderr 1>&2' &> all.txt || true
printf "%s\n" one two three | wc -l | tee count.txt

echo
echo "== Processes & jobs =="
({ sleep 1; echo "bg job done"; } &)
jobs || true
sleep 0.2
ps aux | grep "[c]heatsheet" || true
time sleep 0.1
command -v top >/dev/null 2>&1 && (top -l 1 | head -n 5) || (command -v htop >/dev/null 2>&1 && htop -v || echo "top/htop demo skipped on this OS")

echo
echo "== Permissions & links =="
echo -e '#!/usr/bin/env bash\necho run' > script.sh
chmod 644 script.sh
chmod +x script.sh
./script.sh
ln -s script.sh link_to_script
./link_to_script

echo
echo "== Networking =="
command -v curl >/dev/null 2>&1 && curl -I https://example.com | head -n 5 || echo "curl not installed"
command -v lsof >/dev/null 2>&1 && lsof -i :65535 | head -n 1 || echo "lsof not installed or no process on :65535"
ping -c 1 8.8.8.8 >/dev/null 2>&1 && echo "ping ok" || echo "ping blocked/unavailable"

echo
echo "== Environment & shell =="
echo "$PATH" | tr ':' '\n' | head -n 3
export VAR=value
env | grep '^VAR=' || true
alias gs='echo git status'
gs
unalias gs
history 1 || echo "history not available in non-interactive shell"
echo "!! and !-2 are shell history expansions (not shown in non-interactive script)"

echo
echo "== Compilation (C) =="
SRC_DIR="/Users/timur/develop/labs/os_ta/code/lab02/snippets/c"
cp "$SRC_DIR/hello_world.c" .
gcc hello_world.c -o app
./app | cat
gcc -E hello_world.c -o hello_world.i
gcc -S hello_world.c -o hello_world.s
gcc -c hello_world.c -o hello_world.o
echo "Generated: app, hello_world.i, hello_world.s, hello_world.o"

echo
echo "All demos completed. Playground at $PLAYDIR will be removed."



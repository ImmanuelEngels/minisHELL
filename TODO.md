# 🧠 Minishell TODO

A structured list of tasks and progress tracking for the Minishell project (42 standard).

---

## ⚙️ BUILTINS

### Implement
- [ ] `echo` — with `-n` option
- [ ] `cd` — with relative, absolute, and `~` paths
- [ ] `pwd` — prints current working directory
- [ ] `export` — add or modify environment variables
- [ ] `unset` — remove variables from environment
- [ ] `env` — display the environment
- [ ] `exit` — exit the shell with correct code

### Notes
- Builtins must work both standalone and inside pipelines.
- Environment changes (`export`, `unset`) affect only the current shell.
- `cd` must update `PWD` and `OLDPWD`.
- `exit` must respect numeric argument behavior (`exit 2`, etc.).

---

## 🧩 PARSING

### Tokenization
- [ ] Split input into tokens separated by spaces and special characters.
- [ ] Handle quotes: single (`'`) and double (`"`).
- [ ] Handle redirections (`<`, `>`, `>>`, `<<`).
- [ ] Remove quotes from final arguments.
- [ ] Handle `$` variable expansion inside double quotes and unquoted text.
- [ ] No globbing (`*`, `?`, etc.) or backslash escaping required.

### Syntax Validation
- [ ] Detect unclosed quotes.
- [ ] Detect misplaced pipes or redirections (`|`, `>`, `<`).
- [ ] Ensure correct syntax for heredocs (`<<`).

### Command Structure
- [ ] Build a simple structure or list representing commands and arguments.
- [ ] Identify redirections and pipes for each command node.

---

## 🚨 ERROR HANDLING

### Parser Errors
- [ ] Detect and report syntax errors (e.g. unclosed quotes, invalid tokens).
- [ ] Return exit code `258` for syntax errors.

### Execution Errors
- [ ] Handle “command not found”.
- [ ] Handle permission denied and execution errors.
- [ ] Handle invalid file redirections.
- [ ] Handle failed `fork` or `pipe` calls gracefully.
- [ ] Properly close file descriptors on all errors.

---

## 🔗 PIPELINES & REDIRECTIONS

- [ ] Implement multiple pipes (e.g. `cmd1 | cmd2 | cmd3`).
- [ ] Implement input/output redirections: `<`, `>`, `>>`, `<<`.
- [ ] Handle heredocs (with variable expansion inside).
- [ ] Combine pipes and redirections correctly.
- [ ] Close unused file descriptors.
- [ ] Wait for all child processes before returning to prompt.

---

## 🌱 ENVIRONMENT MANAGEMENT

- [ ] Duplicate environment variables on startup.
- [ ] Implement `$VAR` and `$?` expansion.
- [ ] Update environment dynamically (`export`, `unset`).
- [ ] Handle `$` inside double quotes correctly.
- [ ] Builtins should operate on internal environment structure.

---

## 🧠 SIGNALS

- [ ] Handle `SIGINT` (Ctrl+C) — interrupt current input, display new prompt.
- [ ] Handle `SIGQUIT` (Ctrl+\) — ignored in parent, displayed in child.
- [ ] Handle `EOF` (Ctrl+D) — exit gracefully if line is empty.
- [ ] Restore default signal behavior for child processes.
- [ ] Suppress unwanted `^C` and `Quit (core dumped)` messages.

---

## 🧪 TESTSUITE

- [ ] Create test scripts for builtins.
- [ ] Create tests for syntax errors.
- [ ] Create tests for redirections and pipes.
- [ ] Create tests for variable expansion.
- [ ] Compare minishell output and exit codes with bash.
- [ ] Integrate with `run_tests.sh` for automated checks.

---

## 🔧 GENERAL

- [ ] Ensure no memory leaks (use `valgrind` or `leaks`).
- [ ] Handle all system call errors properly.
- [ ] Maintain code readability and consistent style.
- [ ] Free all allocated memory before exit.
- [ ] Follow 42 Norm standards.

---

### 📦 FUTURE IDEAS (optional)



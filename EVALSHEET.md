# 🧠 Minishell Evaluation Sheet

> Based on the official 42 Intra evaluation form for the Minishell project.

---

## 🧍 Introduction

Please comply with the following rules:

- Remain polite, respectful, and constructive during the evaluation.
- Discuss and identify potential problems together.
- Understand that different interpretations may exist — evaluate honestly.
- Only evaluate **what’s in the official Git repository** of the student(s).
- Clone the repo into an **empty directory** before starting.
- Ensure there are no aliases or hidden code changes.
- You may use test scripts for automation if both sides agree.

---

## 🧰 General Rules

- If the repo is empty, the program doesn’t work, or there are **Norm errors**, **cheating**, or **forbidden functions**, apply the proper flag.
- In case of **cheating**, grade = `-42`.
- In case of **segfaults** or any uncontrolled crash → grade = `0`.
- No memory leaks are allowed.
  - Use `valgrind`, `leaks`, or similar tools.
- You may only edit configuration files if necessary.

---

## 🧪 Mandatory Part Tests

### 🔧 Compilation
- [ ] `make -n` uses `-Wall -Wextra -Werror`
- [ ] Program compiles without errors
- [ ] Makefile does **not** relink unnecessarily

---

### 🧩 Simple Command & Global Variable
- [ ] Execute a simple command (`/bin/ls`)
- [ ] Test an empty command
- [ ] Test only spaces/tabs
- [ ] Confirm only **one global variable** is used (for signal number)
- [ ] No crash or uncontrolled termination

---

### 🧠 Arguments
- [ ] Execute commands with arguments (no quotes)
- [ ] Repeat with different commands
- [ ] No crashes or incorrect behavior

---

### 🗣️ `echo`
- [ ] Works with and without arguments
- [ ] Supports `-n` option
- [ ] Matches Bash output
- [ ] No crashes

---

### 🚪 `exit`
- [ ] Works with and without arguments
- [ ] Handles numeric and invalid arguments correctly
- [ ] Program exits cleanly (relaunch after)
- [ ] No crashes

---

### 🔢 Return Value (`$?`)
- [ ] Execute simple command, then `echo $?`
- [ ] Matches Bash exit status
- [ ] Handles invalid commands (`/bin/ls filethatdoesntexist`)
- [ ] Supports `expr $? + $?` behavior
- [ ] No crashes

---

## 🔔 Signals

Test the following scenarios:

| Situation | Expected Behavior |
|------------|-------------------|
| **Ctrl+C** at empty prompt | New line + new prompt |
| **Ctrl+\\** at empty prompt | Nothing happens |
| **Ctrl+D** at empty prompt | Exit minishell |
| **Ctrl+C** after typing | Clear buffer + new prompt |
| **Ctrl+D** after typing | Do nothing |
| **Ctrl+\\** after typing | Do nothing |
| During blocking command (`cat`, `grep`) | Handle signals like Bash |

✅ Repeat with various commands — no crashes.

---

## 🧾 Quotes

### Double Quotes
- [ ] Handle `" "` correctly
- [ ] Test: `echo "cat lol.c | cat > lol.c"`
- [ ] `$` expansion works inside double quotes
- [ ] No crashes

### Single Quotes
- [ ] Handle `' '` correctly
- [ ] No variable expansion or interpretation
- [ ] `echo '$USER'` → prints `$USER`
- [ ] No crashes

---

## 🌍 Environment & Builtins

### `env`
- [ ] Displays current environment variables

### `export`
- [ ] Creates new variables
- [ ] Updates existing ones
- [ ] Confirm with `env`

### `unset`
- [ ] Removes variables successfully

### `cd`
- [ ] Changes directories correctly
- [ ] Handles `.`, `..`, relative & absolute paths
- [ ] Handles invalid paths gracefully

### `pwd`
- [ ] Prints current working directory correctly

---

## 📂 Paths & Execution

### Relative Path
- [ ] Commands work using relative paths
- [ ] Handles complex relative paths (`../../bin/ls`)

### Environment `PATH`
- [ ] Commands work when PATH is set
- [ ] Unset PATH → commands fail
- [ ] Set multiple directories in PATH (checked left-to-right)

---

## 🔁 Redirections
- [ ] `<`, `>`, `>>`, and `<<` work as expected
- [ ] Multiple redirections work properly
- [ ] `<<` does not add to history
- [ ] No crashes or leaks

---

## 🔗 Pipes
- [ ] Commands with `|` execute correctly (`cat file | grep bla | more`)
- [ ] Handles errors gracefully (`ls filethatdoesntexist | grep bla`)
- [ ] Pipes + redirections work together
- [ ] No crashes

---

## 🧠 History & Robustness
- [ ] Pressing Ctrl+C clears buffer
- [ ] History navigation with ↑ ↓ works
- [ ] Invalid commands print errors but do not crash
- [ ] Long command lines work properly

---

## 💵 Environment Variables
- [ ] `$VAR` expands to its value
- [ ] `$?` expands to last exit code
- [ ] Double quotes interpolate `$`
- [ ] `echo "$USER"` shows correct username

---


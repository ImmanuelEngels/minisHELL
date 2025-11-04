# 🐚 Minishell

> As beautiful as a shell.

---

## Chapter IV — Mandatory Part

### 📌 Program Name
`minishell`

---

### 📁 Turn-in Files
- `Makefile`
- `*.h`
- `*.c`

---

### ⚙️ Makefile Rules
Your Makefile must contain the following rules:
- `NAME`
- `all`
- `clean`
- `fclean`
- `re`

---

### 💡 Arguments
None required.

---

### 🧰 Authorized External Functions

readline, rl_clear_history, rl_on_new_line, rl_replace_line, 
rl_redisplay,add_history, printf, malloc, free, write, access, open, 
read, close, fork, wait, waitpid, wait3, wait4,
signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, 
chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, 
opendir, readdir, closedir, strerror, perror, isatty, ttyname, 
ttyslot, ioctl, getenv, tcsetattr, tcgetattr, 
tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs


---

### 🧩 Libft
✅ **Authorized**

---

### 🧠 Description
Write a small shell program.

Your shell must:

- Display a **prompt** when waiting for a new command.  
- Have a **working command history**.  
- Search and launch the **right executable**, based on the `PATH` variable, or using a **relative** or **absolute** path.  
- Use **at most one global variable**, used **only to store the signal number** received.  
  - This global must **not** contain or access other data structures.
  - “Norm”-type structures in the global scope are **forbidden**.

---

### 🚫 Restrictions
Your shell **must not**:
- Interpret unclosed quotes.  
- Interpret special characters not required by the subject such as:
  - `\` (backslash)
  - `;` (semicolon)

---

### 🧱 Quotes Handling
- **Single quotes (`'`)** prevent interpretation of all meta-characters inside.  
- **Double quotes (`"`)** prevent interpretation of all meta-characters **except** `$`.

---

### 📤 Redirections
Implement the following redirections:

| Operator  | Description                                                       |
|-----------|-------------------------------------------------------------------|
| `<`       | Redirect input                                                    |
| `>`       | Redirect output                                                   |
| `<<`      | Heredoc — read input until a line containing the given delimiter. |
| `>>`      | Redirect output in append mode                                    |

---

### 🔗 Pipes
Implement **pipes (`|`)**.  
- The output of each command in a pipeline should be connected to the input of the next command.

---

### 🌱 Environment Variables
Your shell must:
- Handle `$VAR` — expands to the variable’s value.
- Handle `$?` — expands to the **exit status** of the most recent foreground pipeline.

---

### 🧠 Signals
Your shell must handle:

| Signal    | Keyboard | Behavior                               |
|-----------|----------|----------------------------------------|
| `SIGINT`  | Ctrl + C | Displays a new prompt on a new line    |
| `SIGQUIT` | Ctrl + \ | Does nothing                           |
| `EOF`     | Ctrl + D | Exits the shell gracefully             |

#### In interactive mode:
- **Ctrl + C** → display a new prompt on a new line  
- **Ctrl + D** → exit the shell  
- **Ctrl + \\** → do nothing  

---

### ⚙️ Built-in Commands
You must implement the following builtins:

| Command   | Options / Arguments   | Description                   |
|-----------|-----------------------|-------------------------------|
| `echo`    | `-n` option           | Print text to stdout          |
| `cd`      | r or abs path         | Change directory              |
| `pwd`     | none                  | Print current directory       |
| `export`  | no options            | Set environment variables     |
| `unset`   | no options            | Remove environment variables  |
| `env`     | no arguments          | Display environment variables |
| `exit`    | no options            | Exit the shell                |

---

### 🧹 Memory
- You are **not responsible** for `readline()` leaks.  
- However, **your own code must not leak memory**.

---

### ⚠️ Notes & Limits
- Only follow what is **explicitly required** in this subject.  
- Anything not mentioned here is **not required**.  
- In case of doubt, **take Bash as a reference**.

---

> “You should limit yourself to the subject description. Anything that is not asked is not required.”


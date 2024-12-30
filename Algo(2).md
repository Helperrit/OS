# Process ID Retrieval Program

This program demonstrates how to use the `fork()` system call to create a new process and retrieve the process ID using `getpid()`.

---

## Algorithm

1. **Start the program.**
2. Declare the variables `pid`, `pid1`, and `pid2` for process management.
3. Call the `fork()` system call to create a new process.
4. Check the return value of `fork()`:
   - If `pid == -1`, exit the program as the fork operation failed.
   - If `pid != -1`, retrieve the process ID using `getpid()`.
5. Print the process ID.
6. Stop the program.

---

## Features

- Demonstrates process creation using `fork()`.
- Retrieves and prints process IDs for both parent and child processes.
- Serves as an introduction to basic process management in system programming.

---

## Example Usage

1. Compile the program:
   ```bash
   gcc -o process_id process_id.c

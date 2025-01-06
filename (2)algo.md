# 2. PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEM (fork, getpid, exit)
## Algorithm

1. **Start** the program.
2. Declare the variables `pid`, `pid1`, `pid2`.
3. Call the `fork()` system call to create a process.
4. If `pid == -1`, exit.
5. If `pid != -1`, get the process ID using `getpid()`.
6. Print the process ID.
7. **Stop** the program.


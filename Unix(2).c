#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Creating a new process
    pid = fork();

    if (pid == -1) {
        // Fork failed
        printf("Failed to create process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process ID: %d\n", getpid());
    } else {
        // Parent process
        printf("Parent process ID: %d\n", getpid());
    }

    return 0;
}

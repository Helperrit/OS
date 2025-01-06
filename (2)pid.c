#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = fork();

    if (pid == -1) {
        printf("Error in process creation\n");
        return 1;
    }

    if (pid != 0) {
        printf("Parent process ID: %d\n", getpid());
    } else {
        printf("Child process ID: %d\n", getpid());
    }

    return 0;
}

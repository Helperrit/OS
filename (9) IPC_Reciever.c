#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main() {
    void *shared_memory;
    int shmid;

    // Get shared memory segment (already created by sender)
    shmid = shmget((key_t)2345, 1024, 0666); 
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    printf("Shared memory attached at %d\n", shmid);

    // Attach the shared memory segment
    shared_memory = shmat(shmid, NULL, 0); 
    if (shared_memory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Read data from shared memory
    printf("Data read from shared memory: %s\n", (char *)shared_memory);

    // Detach shared memory
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}

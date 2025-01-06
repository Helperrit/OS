//9. IPC USING SHARED MEMORY (IPC_Sender)
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<string.h>

int main() {
    void *shared_memory;
    int shmid;

    // Create shared memory segment (this will create if it doesn't exist)
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT); 
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    printf("Shared memory created with key %d\n", shmid);

    // Attach the shared memory segment
    shared_memory = shmat(shmid, NULL, 0); 
    if (shared_memory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Write data into shared memory
    printf("Write data to shared memory: ");
    fgets((char *)shared_memory, 100, stdin);  // Read a string from input and store it in shared memory

    printf("Data written to shared memory: %s\n", (char *)shared_memory);

    return 0;
}


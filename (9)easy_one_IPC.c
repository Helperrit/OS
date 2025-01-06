//9. IPC USING SHARED MEMORY
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = 1234; // Shared memory key
    int shmid;
    char *shm, *data;
    const char *message = "Hello, Shared Memory!";

    // Step 3: Create the shared memory segment
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Step 4: Attach the shared memory segment to the process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Step 5: Write the data to the shared memory
    printf("Writing to shared memory: %s\n", message);
    strcpy(shm, message);

    // Step 6: Read the data from shared memory
    printf("Data read from shared memory: %s\n", shm);

    // Step 7: Edit the data in shared memory
    data = shm;
    strcat(data, " Modified by process!");

    // Step 6: Read the modified data
    printf("Modified Data in shared memory: %s\n", shm);

    // Step 8: Detach the shared memory
    shmdt(shm);

    // Step 9: Stop the process
    return 0;
}

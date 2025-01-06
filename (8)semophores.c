#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

// Declare semaphores and variables
sem_t mutex, full, empty;
int buffer = 0;  // Shared buffer (item count)
int max_items = 5;  // Maximum items the buffer can hold

// Function for producer
void producer() {
    sem_wait(&empty);  // Wait if buffer is full
    sem_wait(&mutex);  // Enter critical section

    // Produce an item
    buffer++;
    printf("Producer produces item %d\n", buffer);

    sem_post(&mutex);  // Exit critical section
    sem_post(&full);   // Signal that an item is produced
}

// Function for consumer
void consumer() {
    sem_wait(&full);   // Wait if buffer is empty
    sem_wait(&mutex);  // Enter critical section

    // Consume an item
    printf("Consumer consumes item %d\n", buffer);
    buffer--;

    sem_post(&mutex);  // Exit critical section
    sem_post(&empty);  // Signal that space is available
}

int main() {
    int choice;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);  // Mutex for mutual exclusion (1 means available)
    sem_init(&full, 0, 0);   // Full semaphore starts at 0 (buffer empty initially)
    sem_init(&empty, 0, max_items);  // Empty starts at max_items (buffer full initially)

    while(1) {
        // Prompt user to choose between producer, consumer, or exit
        printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (buffer < max_items) {
                    producer();  // Call producer function
                } else {
                    printf("BUFFER IS FULL\n");
                }
                break;

            case 2:
                if (buffer > 0) {
                    consumer();  // Call consumer function
                } else {
                    printf("BUFFER IS EMPTY\n");
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex, full, empty;
int buffer = 0, max_items = 5;

void producer() {
    sem_wait(&empty); sem_wait(&mutex); 
    buffer++; printf("Producer produces item %d\n", buffer);
    sem_post(&mutex); sem_post(&full); 
}

void consumer() {
    sem_wait(&full); sem_wait(&mutex); 
    printf("Consumer consumes item %d\n", buffer); buffer--;
    sem_post(&mutex); sem_post(&empty); 
}

int main() {
    int choice;
    sem_init(&mutex, 0, 1); sem_init(&full, 0, 0); sem_init(&empty, 0, max_items);
    
    while(1) {
        printf("\n1. PRODUCER\n2. CONSUMER\n3. EXIT\n");
        printf("Enter your choice: "); scanf("%d", &choice);
        
        switch(choice) {
            case 1: if (buffer < max_items) producer(); else printf("BUFFER IS FULL\n"); break;
            case 2: if (buffer > 0) consumer(); else printf("BUFFER IS EMPTY\n"); break;
            case 3: sem_destroy(&mutex); sem_destroy(&full); sem_destroy(&empty); exit(0);
            default: printf("Invalid choice\n"); break;
        }
    }
}

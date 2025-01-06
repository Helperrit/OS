//8. PRODUCER CONSUMER PROBLEM USING SEMAPHORES
#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;
int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}


int main() {
    int n;

    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

    while(1) {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &n);

        switch(n) {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("BUFFER IS FULL\n");
                break;

            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("BUFFER IS EMPTY\n");
                break;

            case 3: printf("Exiting the program.");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}


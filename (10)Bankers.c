//10. BANKERS ALGORITHM FOR DEADLOCK AVOIDANCE
#include <stdio.h>

int main() {
    int p, c, count = 0, terminate = 0;
    int alc[10][10], max[10][10], need[10][10], safe[10], available[10], done[10] = {0};

    // Input number of processes and resources
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &c);

    // Input allocation matrix
    printf("Enter the allocation of resources for all processes (%d x %d matrix):\n", p, c);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }

    // Input maximum matrix
    printf("Enter the maximum resources required by each process (%d x %d matrix):\n", p, c);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("Enter the available resources (%d values):\n", c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate the need matrix
    printf("\nNeed resources matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            if (need[i][j] < 0) {
                printf("Error: Need cannot be negative.\n");
                return -1;
            }
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    // Banker's Algorithm
    while (count < p) {
        int found = 0;
        for (int i = 0; i < p; i++) {
            if (!done[i]) {
                int j;
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j]) {
                        break;
                    }
                }

                if (j == c) {
                    // Safe to execute process
                    safe[count++] = i;
                    for (int k = 0; k < c; k++) {
                        available[k] += alc[i][k];
                    }
                    done[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state.\n");
            return -1;
        }
    }

    // Output results
    printf("\nAvailable resources after completion:\n");
    for (int i = 0; i < c; i++) {
        printf("%d\t", available[i]);
    }
    printf("\n");

    printf("Safe sequence is: ");
    for (int i = 0; i < count; i++) {
        printf("P%d ", safe[i]);
    }
    printf("\n");

    return 0;
}

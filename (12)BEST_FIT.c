//12. BEST FIT - MEMORY ALLOCATION METHODS FOR FIXED PARTITION
#include <stdio.h>

void main() {
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    printf("\n\t\t\tMemory Management Scheme - Best Fit");

    // Input number of blocks
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);

    // Input sizes of blocks
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no.%d: ", i);
        scanf("%d", &b[i]);
    }

    // Input sizes of processes
    printf("\nEnter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no.%d: ", i);
        scanf("%d", &p[i]);
    }

    // Best Fit Allocation
    for (i = 1; i <= np; i++) {
        lowest = 9999; // Reset the lowest for each process
        parray[i] = 0; // Initialize no block allocated

        for (j = 1; j <= nb; j++) {
            if (barray[j] == 0) { // Block not yet allocated
                temp = b[j] - p[i]; // Calculate fragment (remaining space)
                if (temp >= 0 && temp < lowest) { // Find the best fitting block
                    parray[i] = j; // Assign the block to the process
                    lowest = temp; // Update the lowest fragment
                }
            }
        }

        if (parray[i] != 0) { // If a block was allocated
            fragment[i] = lowest; // Store the fragment size
            barray[parray[i]] = 1; // Mark block as allocated
        } else {
            fragment[i] = -1; // No suitable block found
        }
    }

    // Display the results
    printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment");
    for (i = 1; i <= np; i++) {
        printf("\n%d\t\t%d\t\t", i, p[i]);
        if (parray[i] != 0) {
            printf("%d\t\t%d\t\t%d", parray[i], b[parray[i]], fragment[i]);
        } else {
            printf("Not Allocated");
        }
    }
}


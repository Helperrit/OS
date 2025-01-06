//11. FIRST FIT - MEMORY ALLOCATION METHODS FOR FIXED PARTITION
#include<stdio.h>

void main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;

    // Initialize flags and allocation arrays
    for (i = 0; i < 10; i++) {
        flags[i] = 0;       // 0 means not allocated
        allocation[i] = -1; // -1 means no process allocated to this block
    }

    // Get the number of blocks and their sizes
    printf("Enter number of blocks: ");
    scanf("%d", &bno);
    printf("\nEnter size of each block: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    // Get the number of processes and their sizes
    printf("\nEnter number of processes: ");
    scanf("%d", &pno);
    printf("\nEnter size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }

    // First-fit allocation algorithm
    for (i = 0; i < pno; i++) { // Loop through each process
        for (j = 0; j < bno; j++) { // Loop through each block
            if (flags[j] == 0 && bsize[j] >= psize[i]) { // If block is free and large enough
                allocation[j] = i; // Allocate process to block
                flags[j] = 1; // Mark the block as allocated
                break; // Move to the next process
            }
        }
    }

    // Display the allocation details
    printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
    for (i = 0; i < bno; i++) {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]); // Block details
        if (flags[i] == 1) { // If the block is allocated
            printf("%d\t\t\t%d", allocation[i] + 1, psize[allocation[i]]);
        } else { // If the block is not allocated
            printf("Not allocated");
        }
    }
}

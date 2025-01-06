#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, smallest;
    int at[10], bt[10], rt[10]; // Arrival Time, Burst Time, Remaining Time
    int total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nProcess\tAT\tBT\tTAT\tWT\n");

    while (completed < n) {
        smallest = -1;

        // Find the process with the smallest remaining time that has arrived
        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] > 0 && (smallest == -1 || rt[i] < rt[smallest]))
                smallest = i;

        if (smallest == -1) {
            time++;
            continue;
        }

        rt[smallest]--; // Execute process

        if (rt[smallest] == 0) { // Process completed
            completed++;
            int end_time = time + 1;
            int tat = end_time - at[smallest];
            int wt = tat - bt[smallest];

            total_tat += tat;
            total_wt += wt;

            printf("P%d\t%d\t%d\t%d\t%d\n", smallest + 1, at[smallest], bt[smallest], tat, wt);
        }
        time++;
    }

    printf("\nAverage Turnaround Time = %.2f", (float)total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt / n);

    return 0;
}

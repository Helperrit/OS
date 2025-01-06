//6. PRIORITY - CPU SCHEDULING ALGORITHM
#include <stdio.h>

int main() {
    int bt[20], p[20], pri[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    // Get the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Get burst time and priority for each process
    printf("\nEnter Burst Time and Priority:\n");
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for p%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority for p%d: ", i + 1);
        scanf("%d", &pri[i]);
        p[i] = i + 1; // Process ID
    }

    // Sorting processes based on priority (ascending order)
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (pri[j] < pri[pos]) {
                pos = j; // Find process with higher priority (lower value)
            }
        }

        // Swap priorities, burst times, and process IDs
        temp = pri[i];
        pri[i] = pri[pos];
        pri[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j]; // Sum of burst times of all previous processes
        }
        total += wt[i]; // Total waiting time
    }

    // Calculate average waiting time
    avg_wt = (float)total / n;

    // Calculate turnaround time for each process and total turnaround time
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst Time + Waiting Time
        totalT += tat[i]; // Total Turnaround Time
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pri[i], wt[i], tat[i]);
    }

    // Calculate average turnaround time
    avg_tat = (float)totalT / n;

    // Print average waiting and turnaround times
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}

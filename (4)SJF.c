//4. SHORTEST JOB FIRST - CPU SCHEDULING ALGORITHM
#include <stdio.h>

int main() {
    int n, pid[15], bt[15], wt[15], tat[15];
    float twt = 0, ttat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs and burst times (ID BT):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pid[i], &bt[i]);
    }

    // Sort processes by burst time (SJF logic)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                // Swap process IDs
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    wt[0] = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Calculate waiting time
        twt += wt[i];                 // Add to total waiting time
    }

    printf("Process ID  Burst Time  Waiting Time  TurnAround Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i]; // Turnaround time for each process
        ttat += tat[i];         // Add to total turnaround time
        printf("%d           %d            %d            %d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", ttat / n);

    return 0;
}

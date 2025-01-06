//3. FIRST COME FIRST SERVE - CPU SCHEDULING ALGORITHM
#include <stdio.h>

int main() {
    int pid[15], bt[15], wt[15], n;
    float twt = 0, tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process IDs and burst times (ID BT):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pid[i], &bt[i]);
    }

    wt[0] = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        twt += wt[i]; // Add to total waiting time
    }

    printf("Process ID  Burst Time  Waiting Time  TurnAround Time\n");
    for (int i = 0; i < n; i++) {
        int tat_i = wt[i] + bt[i]; // Turnaround time for each process
        tat += tat_i;             // Add to total turnaround time
        printf("%d           %d            %d            %d\n", pid[i], bt[i], wt[i], tat_i);
    }

    printf("Average Waiting Time = %.2f\n", twt / n);
    printf("Average Turnaround Time = %.2f\n", tat / n);

    return 0;
}

//5. SHORTEST REMAINING TIME FIRST (SRTF) - CPU SCHEDULING ALGORITHM
#include <stdio.h>

int main() {
    int n, i, smallest, time, count = 0, end_time;
    int at[10], bt[10], rt[10]; // Arrival Time, Burst Time, Remaining Time
    int wt = 0, tat = 0, completed = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time & Burst Time for Process-%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time as burst time
    }

    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Variables for tracking
    int total_wt = 0, total_tat = 0;

    for (time = 0; completed < n; time++) {
        smallest = -1;

        // Find the process with the smallest remaining time that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (smallest == -1 || rt[i] < rt[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            continue; // If no process is ready, skip the time unit
        }

        // Execute the selected process
        rt[smallest]--;

        // Check if the process is completed
        if (rt[smallest] == 0) {
            completed++;
            end_time = time + 1; // Time at which the process completes
            int turnaround_time = end_time - at[smallest];
            int waiting_time = turnaround_time - bt[smallest];

            total_tat += turnaround_time;
            total_wt += waiting_time;

            // Print details for the completed process
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
                   smallest + 1, at[smallest], bt[smallest], turnaround_time, waiting_time);
        }
    }

    // Calculate averages
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}

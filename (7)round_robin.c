// 7. ROUND ROBIN SCHEDULING - CPU SCHEDULING ALGORITHMS
#include <stdio.h>

int main() {
    // Input number of processes
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    // Declare necessary arrays and variables
    int wait_time = 0, ta_time = 0;
    int arr_time[n], burst_time[n], temp_burst_time[n];
    int x = n; // Process count

    // Input process details (arrival time and burst time)
    for (int i = 0; i < n; i++) {
        printf("Enter Details of Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i]; // Save the burst time for processing
    }

    // Input time slot for round-robin scheduling
    int time_slot;
    printf("Enter Time Slot: ");
    scanf("%d", &time_slot);

    // Initialize counters
    int total = 0, counter = 0, i = 0;
    printf("\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Round Robin Scheduling
    while (x != 0) {
        // If the process can be completed within the time slot
        if (temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0) {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0; // Process completed
            counter = 1; // Mark process as completed
        }
        // If the process needs more time
        else if (temp_burst_time[i] > 0) {
            temp_burst_time[i] -= time_slot;
            total += time_slot;
        }

        // When a process is completed
        if (temp_burst_time[i] == 0 && counter == 1) {
            x--; // Decrease process count
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i],
                   total - arr_time[i], total - arr_time[i] - burst_time[i]);
            // Calculate waiting and turnaround times
            wait_time += total - arr_time[i] - burst_time[i];
            ta_time += total - arr_time[i];
            counter = 0; // Reset counter for the next process
        }

        // Move to the next process
        if (i == n - 1) {
            i = 0; // Reset to the first process
        }
        else if (arr_time[i + 1] <= total) {
            i++;
        }
        else {
            i = 0; // Reset if no process is ready
        }
    }

    // Calculate and print the average waiting and turnaround times
    float average_wait_time = wait_time * 1.0 / n;
    float average_turnaround_time = ta_time * 1.0 / n;
    printf("\nAverage Waiting Time: %.2f", average_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);


    return 0;
}

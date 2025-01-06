## 7. Round Robin Scheduling - CPU Scheduling Algorithm

1. **Input** the number of processes and the burst time (`BT`) of each process.
2. **Input** the time quantum (`TQ`).
3. **Find** the waiting time (`WT`) for each process:
   - Use a circular queue to allocate the CPU to each process for a duration equal to the time quantum.
   - Subtract the time quantum from the remaining burst time of the process.
   - If the remaining burst time becomes 0, calculate the waiting time for that process.
4. **Calculate** the turnaround time (`TAT`) for each process:  
   `TAT[i] = WT[i] + BT[i]`.
5. **Calculate** the average waiting time:  
   `average_waiting_time = total_waiting_time / number_of_processes`.
6. **Calculate** the average turnaround time:  
   `average_turnaround_time = total_turnaround_time / number_of_processes`.

## 6. Priority - CPU Scheduling Algorithm

1. **Input** the number of processes, burst time (`BT`), and priority of each process.
2. **Sort** the processes in ascending order based on their priority.
3. **Find** the waiting time (`WT`) for each process:
   - For the first process: `WT[0] = 0`.
   - For subsequent processes: `WT[i] = BT[i-1] + WT[i-1]`.
4. **Calculate** the turnaround time (`TAT`) for each process:  
   `TAT[i] = WT[i] + BT[i]`.
5. **Calculate** the average waiting time:  
   `average_waiting_time = total_waiting_time / number_of_processes`.
6. **Calculate** the average turnaround time:  
   `average_turnaround_time = total_turnaround_time / number_of_processes`.

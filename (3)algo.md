# 3. FIRST COME FIRST SERVE - CPU SCHEDULING ALGORITHM

## Algorithm

1. **Input** the number of processes.
2. **Input** the processes' burst time (`bt`).
3. **Find** the waiting time (`wt`) for all processes:
   - The first process does not need to wait, so the waiting time for process 1 is `0`, i.e., `wt[0] = 0`.
   - For all other processes, calculate the waiting time as:  
     `wt[i] = bt[i-1] + wt[i-1]` (for process `i`).
4. **Find** the turnaround time (`tat`) for all processes:  
   `tat[i] = wt[i] + bt[i]`.
5. **Calculate** the average waiting time:  
   `average_waiting_time = total_waiting_time / number_of_processes`.
6. **Calculate** the average turnaround time:  
   `average_turnaround_time = total_turnaround_time / number_of_processes`.

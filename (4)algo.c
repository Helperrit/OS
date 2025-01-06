# 4.Shortest Job First (SJF) - CPU Scheduling Algorithm

## Algorithm

1. **Enter** the number of processes.
2. **Enter** the burst time (`BT`) of all the processes.
3. **Sort** all the processes based on their burst time along with their respective process numbers.
4. **Find** the waiting time (`WT`) for all the processes:
   - For the smallest process, `WT = 0`.
   - For all the next processes `i`, calculate the waiting time as:  
     `WT[i] = BT[i-1] + WT[i-1]`.
5. **Calculate** the turnaround time (`TAT`) for all the processes:  
   `TAT[i] = WT[i] + BT[i]`.
6. **Calculate** the average waiting time:  
   `average_waiting_time = total_waiting_time / number_of_processes`.
7. **Calculate** the average turnaround time:  
   `average_turnaround_time = total_turnaround_time / number_of_processes`.

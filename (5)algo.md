## 5. Shortest Remaining Time First (SRTF) - CPU Scheduling Algorithm

1. **Enter** the number of processes.
2. **Enter** the burst time (`BT`) and arrival time (`AT`) of all the processes.
3. **Sort** all the processes based on their arrival time and, in case of ties, by their burst time.
4. **Traverse** until all processes are completely executed:
    - **Find** the process with the minimum remaining time at each time unit.
    - **Reduce** its remaining time by 1.
    - **Check** if its remaining time becomes 0:
        - **Increment** the counter of completed processes.
        - **Set** the completion time for the current process: `completion_time = current_time + 1`.
    - **Calculate** waiting time (`WT`) for each completed process:  
      `WT[i] = completion_time - arrival_time - burst_time`.
    - **Increment** the current time.
5. **Calculate** the turnaround time (`TAT`) for all the processes:  
   `TAT[i] = WT[i] + BT[i]`.
6. **Calculate** the average waiting time:  
   `average_waiting_time = total_waiting_time / number_of_processes`.
7. **Calculate** the average turnaround time:  
   `average_turnaround_time = total_turnaround_time / number_of_processes`.

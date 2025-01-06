## 11. First Fit - Memory Allocation Methods for Fixed Partition

1. **Input** memory blocks with size and processes with size.
2. **Initialize** all memory blocks as free.
3. **Start** by picking each process and check if it can be assigned to the current memory block.
4. If `size_of_process <= size_of_block`, **assign** the process to the block and proceed to the next process.
5. If the process cannot fit in the current block, **continue checking** the subsequent blocks until a suitable one is found.

## 8. Producer-Consumer Problem Using Semaphores

1. **Start** the program.
2. **Declare** the required variables, including semaphores and buffer size.
3. **Initialize** the buffer size and specify the maximum number of items to be produced.
4. **Prompt** the user to select an option: producer, consumer, or exit.
5. If the **producer** is selected:
   - **Check** if the buffer is full. If it is full, the producer should not produce an item.
   - Otherwise, **produce** an item and **increment** the buffer size.
6. If the **consumer** is selected:
   - **Check** if the buffer is empty. If it is empty, the consumer should not consume an item.
   - Otherwise, **consume** an item and **decrement** the buffer size.
7. If **exit** is selected, **terminate** the program.
8. **Stop** the program.

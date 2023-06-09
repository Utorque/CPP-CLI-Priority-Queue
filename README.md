C++/CLI PriorityQueue
---
Basic Priority Queue in managed C++/CLI, using a max heap to keep the highest element at the top of the queue. Like *SortedSet*, it accepts classes implementing **System::IComparable**. 

- Push(): Adds a new element to the queue, ensuring it's placed in the correct position based on its priority.
- Pop(): Removes and returns the highest priority element from the queue.
- Peek(): Returns the highest priority element without removing it from the queue.
- Count(): Returns the number of elements in the queue.  

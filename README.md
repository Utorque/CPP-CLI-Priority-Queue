This class includes basic priority queue operations:

- Push: Adds a new element to the queue, ensuring it's placed in the correct position based on its priority.
- Pop: Removes and returns the highest priority element from the queue.
- Peek: Returns the highest priority element without removing it from the queue.
- Count: Returns the number of elements in the queue.  
---
Private helper methods include:
  
- Parent, Left, Right: Returns the index of the parent, left child, and right child of a given index in a binary heap.
- Swap: Swaps the elements at two positions in the heap.
- HeapifyDown: Moves an element down in the heap to its correct position.  
Note: The CompareTo method of the IComparable interface is used to compare the objects in the queue. The method returns a negative integer, zero, or a positive integer as the first argument is less than, equal to, or greater than the second. This is used to maintain the heap property of the queue.

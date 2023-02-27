/*

A list or collection with the restriction that insertion can be performed
at one end (rear) and deletion can be performed at the other end
[FIFO]

Operations: 
1) Enqueue(x) - at one end [void]
2) Dequeue() - at the other end [int]
3) Front() - just to look at the front of the queue; no return [int]
4) IsEmpty() [int]
5) IsFull() [int]

All of these operations' time complexity is O(1); linear time 

There are two implementation of queues
1) Arrays
2) Linked List

*/

/*

Array Implementation:

There would be two indexes to keep track of: 
1) Front [-1]
2) Rear [-1]

Enqueue(x): Increment Rear and insert at that index
Dequeue(): Increment Front and return that vanished value if necessary
when front==rear, front == rear == -1
IsEmpty(): If both are -1, return True

Circular Arrays Implementation:

There would be no end to the array as long as the whole array is taken
up. The rear would keep on being incremented as long as it doesn't
equal the front index
if (Rear+1)%N == front -> is full 
Rear = (Rear+1) % N 

*/

/*

Linked List Implementation:

No hard and fast limits on the size of the queue.
With array implementation, creating a new bigger array would take O(N)
Also, initial implementation would take up unused memory.

So would need to keep track of the Front and Rear pointer variables.
This is needed to ensure both operations would take O(1) TC

*/
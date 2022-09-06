#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

// Looking at the first element

int peep()
{
    return intArray[front];
}

// Checking if the queue is empty

bool isEmpty()
{
    return itemCount == 0;
}

// Checking if the queue is full

bool isFull()
{
    return itemCount == MAX;
}

// Checking how many elements there are

bool Count()
{
    return itemCount;
}

// Inserting element to queue

void insert(int data)
{
    if (!isFull()){
        if (rear == MAX-1){
            rear = -1;
        }
        intArray[++rear] = data;
        itemCount++;
    }
}

// Popping an element

int pop()
{
    int popped = intArray[front++];
    if (front == MAX){
        front = 0;
    }
    itemCount--;
    return popped;
}

// Show elements in queue

void printQueue()
{
    int i;
    for (i=0; i<MAX-1; i++){
        int temp = front + i;
        if (temp >= MAX){
            temp = temp - MAX;
        }
        printf("%d ->", intArray[temp]);
    }

}

int main() {
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);

   // One way of printing
   printQueue();

   printf("\n");

   // One way of printing
   while(!isEmpty()){
      int n = pop();
      printf("%d ",n);
   }

   return 0;
}

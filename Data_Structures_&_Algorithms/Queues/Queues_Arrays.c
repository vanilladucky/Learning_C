#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

int queue[MAX_SIZE];
int front = -1; 
int rear = -1;

void Enqueue(int val){
    if (front == -1 && rear == -1){
        front = 0;
    }

    rear = (rear+1)%MAX_SIZE; /* Circular Queue */
    
    if (rear == front){
        printf("The queue is full!");
    }
    else{
        queue[rear] = val;
    }
}

void Dequeue(){
    if (front == rear){
        printf("The queue is now empty");
        front = rear = -1;
        return;
    }
    front = (front+1)%MAX_SIZE; // new front index
}

void Print(){
    int tmp = front;
    while (tmp != rear){
        printf("%d->", queue[tmp]);
        tmp = (tmp+1)%MAX_SIZE;
    }
    printf("%d", queue[tmp]);
}

int main(){
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Dequeue();

    Print();
}
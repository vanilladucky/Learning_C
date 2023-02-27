#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List Implementation of Queue

typedef struct node{
    int val;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void Enqueue(int val){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = val;
    tmp->next = NULL;

    if (front == NULL && rear == NULL){
        front = rear = tmp;
        return;
    } // Incase the queue is empty 

    rear->next = tmp;
    rear = tmp;
}

int Dequeue(){
    if (front == NULL){
        printf("Nothing to pop; Queue is empty");
        return 0;
    }
    if (front == rear){
        front = rear = NULL;
        return 0;
    }
    node* tmp = front;
    int pop_value = front->val;
    front = front->next;
    free(tmp);
    return pop_value;
}

void Print(){
    node* tmp = front;
    while (tmp!=rear){
        printf("%d->", tmp->val); 
        tmp = tmp->next;
    }
    printf("%d", tmp->val);
}

int main(){
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Dequeue();

    Print();
}
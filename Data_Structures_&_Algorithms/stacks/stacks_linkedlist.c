#include <stdio.h>
#include <stdlib.h>

/*
Our top can be either head or tail of our linked list.
However, using the tail would take O(N) time complexity.
So it is more efficient to insert and delete at the head node. [O(1)]
*/

typedef struct node{
    int val;
    struct node *next;
}node;

node *top = NULL; // Global Variable

void Push(int val){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->val = val;
    tmp->next = top;
    top = tmp;
}

void Pop(){
    node *tmp;
    if (top == NULL){
        printf("The stack is empty");
        return;
    }
    tmp = top;
    top = top->next;
    free(tmp);
}

void Print(){
    node *tmp = top;
    while (tmp != NULL){
        printf("%d->", tmp->val);
        tmp = tmp -> next;
    }
    return;
}

int main(){
    Push(5);
    Push(10);
    Push(15);
    Pop();
    
    Print();
}
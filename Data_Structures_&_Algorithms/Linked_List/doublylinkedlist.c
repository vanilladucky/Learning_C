#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
}node;

node* head; // Global Variable

node* getnewnode(int val){
    node* tmp = (node*)malloc(sizeof(node)); // Will allocate memory on the HEAP instead of the STACK 
    tmp->val = val;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

void enter_front(int val){
    node* tmp = getnewnode(val);

    if (head == NULL){
        head = tmp;
        return;
    }

    else{
        head->prev = tmp;
        tmp->next = head;
        tmp->prev = NULL;
        head = tmp;
        return;
    }
}

void print(node* head){
    node* curr = head;
    while (curr!= NULL){
        printf("%d->", curr->val);
        curr = curr->next;
    }
}

int main(){
    enter_front(5);
    print(head);
}
#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * next;
}node;

void printlist(node *head){
    node *curr = head;

    while (curr != NULL){
        printf("%d->", curr->val);
        curr = curr->next;
    }

    printf("\n");
}

void addtoend(node *head, int val){
    node *curr = head;

    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = (node*)malloc(sizeof(node));
    curr->next->val = val;
    curr->next->next = NULL;
}

void push(node **head, int val){ // Need to remember to use double pointers when attempting to change the head itself - which is the case for when pushing
    node *new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = *head;
    *head = new;
}

int pop(node **head){

    if (*head == NULL){
        return -1;
    }

    node *next = (*head)->next;
    int popped_val = (*head)->val;

    free(*head);
    *head = next;

    return popped_val;
}

int remove_last(node *head){ // Remember that we have to use double pointers only when we wish to alter that specific pointer itself
    int removal;

    node *curr = head;
    while (curr->next->next != NULL){
        curr = curr->next;
    }

    node *tmp = curr->next;
    removal = tmp->val;

    curr->next = NULL;
    free(tmp);

    return removal;
}

int main(){
    node * head = NULL;
    head = (node*)malloc(sizeof(node));

    head->val = 5;
    head->next = (node*)malloc(sizeof(node));

    head->next->val = 6;
    head->next->next = NULL;

    printlist(head);

    addtoend(head, 7);
    printlist(head);

    push(&head, 4);
    printlist(head);

    pop(&head);
    printlist(head);

    remove_last(head);
    printlist(head);
}
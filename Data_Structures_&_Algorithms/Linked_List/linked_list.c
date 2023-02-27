#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

void insert_begin(node** head, int val){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = val;
    tmp->next = *head;

    *head = tmp;
}

void insert_end(node* head, int val){
    node* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }

    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = val;
    tmp->next = NULL;

    curr->next = tmp;
}

void end_ele(node* head){
    node* curr = head;
    while (curr->next!=NULL){
        curr = curr->next;
    }
    printf("The last element is %d", curr->val);
}

int main(){
    node *head = (node*)malloc(sizeof(node));

    head->val = 5;
    head->next = NULL;

    printf("The value of head is %d\n", head->val);

    node *second = (node*)malloc(sizeof(node));

    second->val = 6;
    second->next = NULL;

    head->next = second;

    printf("The value of the second element is %d\n", head->next->val);

    insert_begin(&head, 1);

    printf("The first value now is %d", head->val);

    insert_end(head, 10);
    end_ele(head);
}
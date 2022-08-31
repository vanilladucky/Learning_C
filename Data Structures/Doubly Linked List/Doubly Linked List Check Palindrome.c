#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// About Doubly Linked List

// Declaring the node for a doubly linked list

struct Node
{
    int data;
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to previous node
};

// Function to add node at the front

void push(struct Node** head, int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = val;
    temp -> next = *head;
    temp -> prev = NULL;
    if ((*head) != NULL){
        (*head) -> prev = temp;
    }
    *head = temp;
    return;
}

// Function to add a node after a given node

void insertafter(struct Node* prev_node, int val)
{
    if (prev_node == NULL){
        printf("The previous node cannot be a NULL value. Please look again\n");
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = val;
    temp -> next = prev_node -> next;
    temp -> prev = prev_node;
    prev_node -> next = temp;
    if (temp->next != NULL){
        temp->next->prev = temp;
    }
    return;
}

// Add a node at the end

void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return;
}

// Traversal in both directions

void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

// Checking if it's a palindrome or not

bool palindrome(struct Node* left)
{
    if (left == NULL){
        return true;
    }
    struct Node* right = left;
    while(right->next != NULL){
        right = right->next;
    }
    while (left != right){
        if (left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}


int main()
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    printf("\n");

    if (palindrome(head)){
        printf("\nIt is a Palindrome\n");
    }
    else {
        printf("\nIt isn't a Palindrome\n");
    }

    return 0;
}

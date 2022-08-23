#include<stdio.h>

// About Linked List and its operations

// Initializing Linked List
struct Node {
    int data; // Value
    struct Node* next; // Pointer to the next node
};

void printlist(struct Node* ptr);

int main()
{
    printf("\n");
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node)); // malloc() returns a pointer of type struct Node
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 1;
    head -> next = second;

    second -> data = 2;
    second -> next = third;

    third -> data = 3;
    third -> next = NULL;

    printlist(head);

    printf("\n");
    return 0;
}


// Traversal of Linked list

void printlist(struct Node* ptr)
{
    while (ptr != NULL){
        printf(" %d -> ", ptr -> data);
        ptr = ptr -> next;
    }

    printf("NULL");
}

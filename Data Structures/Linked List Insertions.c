#include<stdio.h>

// About Linked List and its operations

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

// Traversal of Linked List

void printList(struct Node *node)
{
  printf("\n");

  while (node != NULL)
  {
     printf("%d -> ", node->data);
     node = node->next;
  }

  printf("NULL ");
  printf("\n");
}

// Insertion at the beginning

void push(struct Node** head_ref, int value) // Double pointer (It is a very important aspect of this implementation of Insertion)
{
    struct Node* temp_node = (struct Node*)malloc(sizeof(struct Node));
    temp_node -> data = value;
    temp_node -> next = *head_ref; // Ensuring the next pointer of the temp_node is the pointer to head
    *head_ref = temp_node; // Making the new node as the head node now
    return;
}

// Appending at the end

void append(struct Node** head_ref, int value)
{
    struct Node* temp_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref; // Creating a temporary pointer to be used for traversing later on

    temp_node -> data = value;
    temp_node -> next = NULL;

    while (temp->next != NULL){
        temp = temp->next; // Reaching the end node of the Linked List
    }

    temp -> next = temp_node;

    return;
}

// Inserting at a specific index

void insert(struct Node** head_ref, int value, int index)
{
    struct Node* temp_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    int i = 0;

    temp_node -> data = value;

    while (i < index-1){
        if (temp->next != NULL){
            temp = temp -> next;
        }
        else {
            printf("Index is out of range");
            return;
        }
        i++;
    }
    // temp is the previous node
    // temp->next is the next node
    // temp_node is the one going in the middle

    struct Node* next_node = temp->next;
    temp -> next = temp_node;
    temp_node -> next = next_node;

    return;
}

int main()
{
    struct Node* head = NULL;
    push(&head, 5); // Inserting 5 at the beginning of the linked list
    push(&head, 30);
    append(&head, 50);
    insert(&head, 40, 1);

    printList(head); // Checking whether it worked; should give us 30 -> 40 -> 5 -> 50 -> NULL

    return 0;
}

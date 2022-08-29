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

// Deleting a node at a specific index

void del(struct Node** head_ref, int index)
{
    struct Node* temp = *head_ref;
    int i = 0;

    while (i < index-1){
        if (temp->next != NULL){
            temp = temp -> next;
        }
        i++;
    }

    if (temp->next == NULL){
        printf("Index %d is out of range", index);
        goto end;
    }
    // temp is the previous node
    // temp->next is the node to be deleted
    // temp->next->next is the node to be connected
    if (temp->next->next != NULL){
        struct Node* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        goto end;
    }
    else { // Means removing the last element
        temp->next = NULL;
        goto end;
    }

    printf("Index %d is out of range", index);

    end:
    return 0;
}

// Reversing a Linked List (Iteration)

void reverse(struct Node** head_ref)
{
    struct Node* next;
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    while (current != NULL){
        next = current->next;
        current-> next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return;
}

// Reversing a Linked List (Recursion)

// A simple and tail-recursive function to reverse
// a linked list.  prev is passed as NULL initially.
void reverseUtil(struct Node* curr, struct Node* prev, struct Node** head)
{
    /* If last node mark it head*/
    if (curr->next == NULL) {
        *head = curr;
        /* Update next to prev node */
        curr->next = prev;
        return;
    }

    /* Save curr->next node for recursive call */
    struct Node* next = curr->next;
    /* and update next ..*/
    curr->next = prev;
    reverseUtil(next, curr, head);

    return;
}

// This function mainly calls reverseUtil()
// with prev as NULL
void reverse_recursive(struct Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}



int main()
{
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 30);
    push(&head, 200);
    append(&head, 50);
    append(&head, 10000);
    insert(&head, 40, 1);
    insert(&head, 30 ,2);

    printList(head);

    del(&head, 1);

    printList(head);

    reverse(&head);

    printList(head);

    reverse_recursive(&head);

    printList(head);

    return 0;
}
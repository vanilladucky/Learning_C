#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
};

int isEmpty(struct Node* root)
{
    return !root;
}

void push(struct Node** root, int data)
{
    struct Node* newnode = newNode(data);
    newnode -> next = *root;
    *root = newnode;
    printf("%d pushed to stack\n", data);
}

int pop(struct Node** root)
{
    if (isEmpty(*root)){
        printf("The stack is empty");
        return INT_MIN;
    }
    struct Node* temp = *root;
    int popped_data = (*root)->data;
    *root = (*root)->next;
    free(temp);
    return popped_data;
}

int peek(struct Node* root)
{
    if (isEmpty(root)){
        printf("The stack is empty");
        return INT_MIN;
    }
    return root->data;
}

int main()
{
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);


    printf("%d popped from stack\n", pop(&root));

    printf("Top element is %d\n", peek(root));

    return 0;
}

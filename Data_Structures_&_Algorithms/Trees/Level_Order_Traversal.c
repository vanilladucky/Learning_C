#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 101 

/*
We would have to utilize a queue data structure.
As long as the queue is not empty, we will pop the first element from the queue
and enqueue it's children.
*/

typedef struct node {
    char data;
    struct node* left;
    struct node* right;
}node;

// Linked List implementation of Queue


node** createQueue(int* front, int* rear){
    node** queue = (node**)malloc(sizeof(node*)*MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}

void Enqueue(node** queue, int* rear, node* new_node){
    queue[*rear] = new_node;
    (*rear)++;
}

node* Dequeue(node** queue, int *front){
    (*front)++;
    return queue[(*front)-1];
}
// Finished Implementation of Queue


// Implementation of the Level Order Traversal method 

void printLevelOrder(node* root){
    int rear, front;
    struct node** queue = createQueue(&front, &rear);
    node* tmp = root;

    while (tmp){
        printf("%c", tmp->data);

        if (tmp->left){
            Enqueue(queue, &rear, tmp->left);
        }

        if (tmp->right){
            Enqueue(queue, &rear, tmp->right);
        }

        tmp = Dequeue(queue, &front);
    }
}

// End of Level Order Traversal implemenetation

// Driver program

node* newNode(char val){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->left = new_node->right = NULL;

    return new_node;
}

int main(){
    node* root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');

    printf("Level Order Traversal of this binary tree is \n");
    printLevelOrder(root);

    // Level order traversal should return to us a, b, c, d, e
}
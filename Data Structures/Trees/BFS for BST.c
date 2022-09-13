#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_Q_SIZE 500

// Defining a single node for a tree

struct node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Functions we would be needing later on
struct node** createQueue(int*, int*);
void enQueue(struct node**, int*, struct node*);
struct node* deQueue(struct node**, int*);

struct node** createQueue(int* front, int* rear)
{
    struct node** queue = (struct node**)malloc(
        sizeof(struct node*) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
};

void enQueue(struct node** queue, int* rear,
             struct node* new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
};

struct node* deQueue(struct node** queue, int* front)
{
    (*front)++;
    return queue[*front -1];
};

// BFS

void bfs(struct node* root)
{
    int rear, front;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        /*Enqueue left child */
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        /*Enqueue right child */
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}



// Inserting a node into a Binary Search Tree (BST)

struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Inserting a node into a Binary Search Tree (BST)

struct node* insert(struct node** root, int data)
{
    // when tree is empty

    if ((*root)==NULL){ // Will always reach this if statement
        *root = newNode(data);
        return *root;
    }
    else if (data <= (*root)->data){
        (*root)->left = insert(&((*root)->left), data);
    }
    else {
        (*root)->right = insert(&((*root)->right), data);
    }

    return *root;
}

int main()
{
    struct Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

/*            50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    bfs(root);

    return 0;
}

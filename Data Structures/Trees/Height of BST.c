#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

// Defining a single node for a tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Inserting a node into a Binary Search Tree (BST)

struct Node* insert(struct Node** root, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;

    // when tree is empty

    if ((*root)==NULL){ // Will always reach this if statement
        *root = temp;
        return *root;
    }
    else if (data <= (*root)->data){
        (*root)->left = insert(&((*root)->left), data);
    }
    else {
        (*root)->right = insert(&((*root)->right), data);
    }
}

// Finding height of binary tree

int FindHeight(struct Node* root)
{
    if (root == NULL){
        return 0;
    }
    return max(FindHeight(root->left), FindHeight(root->right))+1;
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

    printf("The height of this BST is %d\n", FindHeight(root));

    return 0;
}

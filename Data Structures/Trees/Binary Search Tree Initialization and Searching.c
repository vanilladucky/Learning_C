#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

    if ((*root)==NULL){
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

// Searching whether an element is in the BST

bool search(struct Node** root, int data)
{
    if (*root == NULL){
        return false;
    }
    else if ((*root)->data == data){
        return true;
    }
    else if (data <= (*root)->data){
        return search(&((*root)->left), data);
    }
    else {
        return search(&((*root)->right), data);
    }
}

int main()
{
    struct Node* root = NULL;
    insert(&root, 5);
    insert(&root, 10);
    insert(&root, 3);

    // Checking if one of the above element is in the tree
    int exist = 5;
    int missing = 4;
    if (search(&root, exist)){
        printf("There is the number %d in the tree\n", exist);
    }
    else {
        printf("Error detected with searching function!");
    }

    if (!search(&root, missing)){
        printf("There is no number %d in the tree\n", missing);
    }
    else {
        printf("Error detected with searching function!");
    }
}

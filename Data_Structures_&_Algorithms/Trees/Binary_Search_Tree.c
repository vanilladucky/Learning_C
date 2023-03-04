/*

Binary Search Tree operations:
Insertion, Deletion, Search - O(logn)

Implementation:
1) Array
2) Memory allocated nodes 
    * one for data
    * two pointer to node for children

Values in the left subtree is lesser or equal and values in the right subtree is greater


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(i, j) (((i) > (j)) ? (i) : (j))

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* getnewnode(int data){// Function to make a new node using malloc on stack
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void Insert(node** root, int data){
    if (*root == NULL){
        *root = getnewnode(data);
    }
    else if (data <= (*root)->data){
        Insert(&((*root)->left), data);
    }
    else{
        Insert(&((*root)->right), data);
    }
}

bool Search(node* root, int data){
    if (root == NULL){
        return false;
    }
    else if (root->data == data){
        return true;
    }
    else if (data <= root->data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

// Finding minimum and maximum value in a BST

int Findmin(node* root){
    while (root->left!=NULL){
        root = root->left;
    }
    return root->data; 
}

// Finding height of a binary tree
// Number of edges in longest path from node to a leaf node

int FindHeight(node* root){
    if (root == NULL){
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// Binary Tree Traversal

/*

Breadth-first 
    * level-order traversal

Depth-first
    * <root><left><right> - preorder traversal
    * <left><root><right> - inorder traversal
    * <left><right><root> - postorder traversal

Inorder traversal would give us back the sorted binary tree in a list

*/




int main(){
    node* root = NULL;
    Insert(&root, 15); // Since the root is a local variable
    Insert(&root, 10);
    Insert(&root, 5);

    if (Search(root, 9)){
        printf("Number found\n");
    }
    else{
        printf("Number not found\n");
    }

    printf("The minimum values of the BST is %d\n", Findmin(root));

    printf("The height of the binary tree is %d\n", FindHeight(root));
}
/*
Deleting a leaf node is pretty simple.
The previous node has to be linked to a Null node and the freed node's memory has to be freed, let go.

What if the node to be deleted only has 1 child? 
We just need to link the parent node to the child node. 

What if the node to be deleted has 2 children? [The trickiest scenario]
Obtain the minimum value from the right subtree and replace it with that. 
And then we would need to delete the duplicate from the right subtree 
OR
Obtain the maximum in left and copy the value to the node.
We then delete the duplicate from left subtree. 
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
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

node* FindMin(node *nd){
    if (nd->left==NULL){
        return nd;
    }
    return FindMin(nd->left);
}

node* Delete(node *root, int data){ // will pass in address of the root node along with the data to be deleted 
    if (root==NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else{ // When we found the data to be deleted 
        // Case 1: No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        // Case 2: 1 child 
        else if (root->left == NULL){
            node *tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right == NULL){
            node *tmp = root;
            root = root->left;
            free(tmp);
        }
        // Case 3: 2 children 
        else {
            node *tmp = FindMin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
} 


void InOrder(node *root){
    if (root==NULL) return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

int main(){
    node* root = NULL;
    Insert(&root, 15); // Since the root is a local variable
    Insert(&root, 10);
    Insert(&root, 5);
    Insert(&root, 20);
    Insert(&root, 2);
    Insert(&root, 67);

    InOrder(root);

    root = Delete(root, 20);
    printf("\n");
    InOrder(root);
}
/*
Inorder Successor means the value that comes right after that value in an order traversal.
That would mean we are finding the value that is the next larger value.

Case 1: If target node has right sub-tree
If the target node has a right sub tree, the value we are looking for would be the
minimum value in the right subtree.
 
Case 2: If target node has no right sub-tree
Go to the nearest ancestor for which the target node would be in the ancestor's left subtree.
This means we would have to design the node which includes pointer to the parent node.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

node* Find(node *root, int data){
    if (root->data == data){
        return root; // Terminating Condition
    }

    if (root->data < data){
        return Find(root->right, data);
    }
    else{
        return Find(root->left, data);
    }
}

node* GetSuccessor(node *root, int data){
    // Search for the node
    node *current = Find(root, data);
    if (current == NULL) return NULL;

    // Case 1: Node has right subtree
    if (current -> right != NULL){
        node *tmp = current->right;
        while (tmp->left != NULL) tmp = tmp->left;
        return tmp; // Found minimum value in the right sub-tree
    }

    // Case 2: Node has no right subtree
    else{
        node *successor = NULL;
        node *ancestor = root;
        while (ancestor != current){
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main(){

    node *root = (node*)malloc(sizeof(node));
    root->data = 12;

    root->left = (node*)malloc(sizeof(node));
    root->left->data = 5;

    root->right = (node*)malloc(sizeof(node));
    root->right->data = 15;

    root->left->left = (node*)malloc(sizeof(node));
    root->left->left->data = 3;

    root->left->right = (node*)malloc(sizeof(node));
    root->left->right->data = 7;

    root->left->left->left = (node*)malloc(sizeof(node));
    root->left->left->left->data = 1;

    root->left->right->right = (node*)malloc(sizeof(node));
    root->left->right->right->data = 9;

    root->right->left = (node*)malloc(sizeof(node));
    root->right->left->data = 13;

    root->right->right = (node*)malloc(sizeof(node));
    root->right->right->data = 17;

    node *successor = GetSuccessor(root, 3);
    printf("The successor's data is %d", successor->data);
}
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

// A utility function to create a new BST node
struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inserting a node into a Binary Search Tree (BST)

struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
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

// Preorder Traversal (root node -> left subtree -> right subtree)

void preOrder(struct Node* root){
   if(root!=NULL){
      printf("%d ",root->data);
      preOrder(root->left);
      preOrder(root->right);
   }
}

// Inorder Traversal (left, root, right)

void Inorder(struct Node* root)
{
    if (root != NULL){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

// Postorder Traversal (left, right, root)

void Postorder(struct Node* root)
{
    if (root != NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 11);
    insert(root, 20);
    insert(root, 3);
    insert(root, 42);
    insert(root, 54);
    insert(root, 16);
    insert(root, 32);
    insert(root, 9);
    insert(root, 4);
    insert(root, 10);

    // Checking if one of the above element is in the tree
    int number = 20;
    if (search(&root, number)){
        printf("There is the number %d in the tree\n", number);
    }
    else {
        printf("The number %d doesn't exist in the tree\n", number);
    }

    // Preorder Traversal
    printf("\n");
    preOrder(root);
    printf("\n");

    // Inorder Traversal
    printf("\n");
    Inorder(root);
    printf("\n");

    // Postorder Traversal
    printf("\n");
    Postorder(root);
    printf("\n");
}

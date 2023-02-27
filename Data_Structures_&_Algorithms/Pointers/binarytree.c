#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node * left;
  struct node * right;
} node_t;

void insert(node_t * tree,int val);
void print_tree(node_t * current);
void printDFS(node_t * current);

int main()
{
  node_t * test_list = (node_t *) malloc(sizeof(node_t));
  /* set values explicitly, alternative would be calloc() */
  test_list->val = 0;
  test_list->left = NULL;
  test_list->right = NULL;

  insert(test_list,5);
  insert(test_list,8);
  insert(test_list,4);
  insert(test_list,3);

  printDFS(test_list);
  printf("\n");
}

void insert(node_t *root, int val){
    if (root->val == 0){
        root->val = val;
    }
    else{
        if (val < root->val){ // go to the left
            if (root->left != NULL){
                insert(root->left, val);
            }
            else {
                node_t * new_tree = (node_t*)malloc(sizeof(node_t));
                new_tree -> val = val;
                new_tree -> left = NULL;
                new_tree -> right = NULL;
                root->left = new_tree;
            }
        }
        else {
            if (root->right != NULL){
                insert(root->right, val);
            }
            else{
                node_t * new_tree = (node_t*)malloc(sizeof(node_t));
                new_tree -> val = val;
                new_tree -> left= NULL;
                new_tree -> right = NULL;
                root->right = new_tree;
            }
        }
    }
}

/* depth-first search */
void printDFS(node_t * current)
{
  /* change the code here */
  if (current == NULL)         return;   /* security measure */
  if (current != NULL)         printf("%d ", current->val);
  if (current->left != NULL)   printDFS(current->left);
  if (current->right != NULL)  printDFS(current->right);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
We can reverse a string using stacks.
Words are pushed onto the stack and thus the last word would be the top of the stack
*/

// --------Declaring Stack---------- //

typedef struct node{
    char val;
    struct node *next;
}node;

void Push(node** top, char val){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->val = val;
    tmp->next = *top;
    *top = tmp;
}

char Pop(node **top){
    node* tmp;
    if ((*top) == NULL){
        printf("The stack is empty");
        return 0;
    }
    tmp = *top;
    *top = (*top)->next;
    char return_char = tmp->val;
    free(tmp);
    return return_char;
}

// --------Declaring Stack---------- //

void Reverse(node** top, char C[], int length){
    for (int i = 0; i < length; i++){
        Push(top, C[i]);
    }

    for (int i = 0; i < length; i++){
        C[i] = Pop(top);
    }
}

int main(){
    node* top = NULL;
    char C[51] = {'a', 'b', 'c', 'd'};
    Reverse(&top, C, 4);
    printf("Output is %s", C);
}
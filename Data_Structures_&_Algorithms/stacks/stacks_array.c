#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101 // Global Variable

/*
Must only access the top element at a single time

Definition: list with the restriction that insertion and deletion
can be performed only from one end, the top [LIFO]

Operations: [O(1)]
    1) Push(x) - pushing element to top of stack
    2) Pop() - removing top element and returning it
    3) Top() - just returns top element
    4) IsEmpty() - check if empty or not 

Applications:
    1) Function calls / Recursion
    2) Undo Operation
    3) Balanced Parenthesis 
*/

// Arrays Implementation

void push(int x, int *top, int (*A)[]){
    if (*top == MAX_SIZE-1){
        printf("Error: stack-overflow");
        return;
    }
    //*top = *top + 1;
    (*A)[++(*top)] = x;
} 

void pop(int *top){
    if ((*top) == -1){
        printf("No element to pop");
        return;
    }
    (*top)--;
}

void print_stack(int top, int stack[]){
    for (int i = 0; i < top+1; i++){
        printf("%d->", stack[i]);
    }
}

int top_ele(int top, int stack[]){
    printf("%d\n", stack[top]);
    return stack[top];
}

void IsEmpty(int top){
    if (top == -1){
        printf("The stack is empty\n");
        return;
    }
    printf("The stack is not empty\n");
}

int main(){
    int A[MAX_SIZE];
    int top = -1; // The index for the top value
    push(5, &top, &A);
    push(10, &top, &A);
    push(15, &top, &A);
    pop(&top);
    top_ele(top, A);
    IsEmpty(top);
    print_stack(top, A);
}
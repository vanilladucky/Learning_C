#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

// Add element to the top of stack

void Push(int x)
{
    if (top == MAX_SIZE){
        printf("\nERROR : STACK OVERFLOW\n");
        return;
    }
    top++;
    A[top] = x;
}

// Popping an element which will return the element and discard it

int Pop()
{
    if (top == -1){
        printf("\nThere is nothing to pop\n");
        return 0;
    }
    return A[top];
    top--;
}

// Just return the top element

void Top()
{
    return A[top];
}

// Print the stack

void Print()
{
    int i;
    printf("Stack: ");
    for (i=0; i < top; i++){
        printf("%d", A[i]);
    }
    printf("\n");
    return;
}

int main()
{
    int pop;
    Push(5);
    Push(2);
    Push(3);
    Push(4);
    pop = Pop();
    printf("The popped element is %d\n", pop);
    Print();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 101

//--------Stack Implementation---------//

void push(char x, int *top, char (*A)[]){
    if (*top == MAX_SIZE-1){
        printf("Error: stack-overflow");
        return;
    }
    *top = *top + 1;
    (*A)[*top] = x;
} 

void pop(int *top){
    if ((*top) == -1){
        printf("No element to pop");
        return;
    }
    (*top)--;
}

int IsEmpty(int top){
    if (top == -1){
        return 0;
    }
    return 1;
}

//--------Stack Implementation---------//

int check(char paran[], int length){
    if (length%2 == 1){
        printf("Incorrect due to odd length");
        return 0;
    }
    int top = -1;
    char stack[MAX_SIZE];
    for (int i = 0; i < length; i++){
        if (paran[i] == '(' || paran[i] == '{' || paran[i] == '['){
            push(paran[i], &top, &stack);
        }
        else if (paran[i] == ')' || paran[i] == '}' || paran[i] == ']'){
            if (IsEmpty(top) == 0){
                printf("%d", 1);
                printf("Incorrect");
                return 0;
            }
            else if (paran[i] == ')' && paran[top] != '('){
                printf("%d", 2);
                printf("Incorrect");
                return 0;
            }
            else if (paran[i] == '}' && paran[top] != '{'){
                printf("%d", 3);
                printf("Incorrect");
                return 0;
            }
            else if (paran[i] == ']' && paran[top] != '['){
                printf("%c", paran[top]);
                printf("Incorrect");
                return 0;
            }
            pop(&top);
        }
    }
    if (IsEmpty(top) == 0){
        printf("Correct");
        return 1; // correct
    }
    else {
        printf("Incorrect");
        return 0; // incorrect
    }
}

int main(){
    char paran[] = "()[]{}";
    check(paran, strlen(paran));
}
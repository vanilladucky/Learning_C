#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Infix - <operand><operator><operand> eg.) 2+3 [Most human readable]
postfix - <operator><operand><operand> eg.) +23
Postfix -  <operand><operand><operator> eg.) 23+ [Most Effective]
*/

// For postfix:
// The 2 preceding operands to an operator would be the operands the
// operator is working on. 

// For Postfix:
// We have to start analyzing from the right.

// Infix to Postfix Algorithm [O(N)]
/*
    for i to length 
        if exp[i] is operand:
            res.append(exp[i])
        else if (exp[i] is operator):
            while (!s.empty && HasHigherPrecedence(s.top, exp[i])){
                // when s.top has higher precendence than exp[i]
                res.append(s.top)
                s.pop()
            }
            s.push(exp[i])
    while (!s.empty()){
        res.append(s.top())
        s.pop()
    }
    return res 
*/

#define MAX_SIZE 101

char stack[MAX_SIZE]; // Global Variable
int top = -1; // Global Variable
char postfix[MAX_SIZE]; // Global Variable -> result 
int postfix_idx = 0;

void Push(char c){
    if (top == MAX_SIZE-1){
        printf("Error: Stack Overflow!");
    }
    stack[++top] = c;
}

char Pop(){
    if (top == -1){
        printf("Empty stack");
        return 0;
    }
    char tmp = stack[top];
    top--;
    return tmp;
}

int IsEmpty(){
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int HasHigherPrecendence(char top, char ele){
    // return true when the top value has higher precedence than the element in question
    if (IsEmpty() == 1){
        return 0;
    }
    if ( (ele == '+' || ele == '-') && (top == '*' || top == '/') ){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char infix[] = "2*3+6*3";
    int length = strlen(infix);

    for (int i = 0; i < length; i++){
        if (infix[i] != '+' && infix[i] != '-' && infix[i] != '*' && infix[i] != '/'){
            //printf("First\n"); // Debugging
            postfix[postfix_idx] = infix[i];
            postfix_idx++;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            //printf("Second\n"); // Debugging
            while (IsEmpty() == 0 && HasHigherPrecendence(stack[top], infix[i])==1){
                postfix[postfix_idx] = Pop();
                postfix_idx++;
            }
            Push(infix[i]);
        }
    }
    while (IsEmpty() == 0){
        //printf("Third\n"); // Debugging
        postfix[postfix_idx] = Pop();
        postfix_idx++;
    }
    printf("%s\n", infix);
    printf("%s\n", postfix);
}
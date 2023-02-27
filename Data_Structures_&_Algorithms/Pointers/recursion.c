#include<stdio.h>
#include <stdlib.h>

// Factorial Recursion

unsigned int factorial(unsigned int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int main(){
    int i = 5;
    printf("The factorial of %d is %d\n", i, factorial(i));
}
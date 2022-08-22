#include <stdio.h>
#include <stdlib.h>


int main() {

    float first_number;
    float second_number;
    char operate;
    float result;

    printf("Enter your expression: ");
    scanf("%f%c%f", &first_number, &operate, &second_number);

    switch(operate)
    {
    case '+':
        result = first_number + second_number;
        break;
    case '-':
        result = first_number - second_number;
        break;
    case '*':
        result = first_number * second_number;
        break;
    case '/':
        result = first_number/second_number;
        break;
    default:
        goto fail;
    }

    printf("The answer is: %f", result);
    goto pass;

    fail:
        printf("This is an invalid operator");

    pass:
        return 0;
}

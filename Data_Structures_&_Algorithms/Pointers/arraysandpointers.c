/*
    We can have pointers to arrays
    The name of an array itself is a (constant) pointer to the first element of the array
*/

#include<stdio.h>
#include <stdlib.h>

int main() {
    char vowels[] = "Kim";
    char *pvowels = vowels; // the 'vowels' itself is already a pointer - pointing to the first character of the whole string 

    printf("%p \n", &vowels[0]);
    printf("%p \n", vowels); // These two will refer to the same address - the starting point of the whole string "Kim"

    int n = 5;
    char *ppvowels = (char *)malloc(n * sizeof(char));
    int i;

    ppvowels[0] = 'a'; // ppvowels is actually a POINTER
    ppvowels[1] = 'b';
    ppvowels[2] = 'c';
    ppvowels[3] = 'd';
    ppvowels[4] = 'e';

    for (i=0; i < n; i++){
        printf("The values are %c \n", *(ppvowels+i));
    }

    return 0;

    free(pvowels);
    free(ppvowels);
}
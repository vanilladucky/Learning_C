#include<stdio.h>
#include <stdlib.h>
typedef struct {
        int a;
        int b;
    } coor;

int main()
{
    coor *coordinates = (coor *)malloc(sizeof(coor));
    coordinates->a = 5;
    coordinates->b = 6;

    printf("%d", (*coordinates).a);
}

/*
    malloc will dynamically allocate the amount of size as requested 
    it will return a POINTER of the type (coor in this case)
*/
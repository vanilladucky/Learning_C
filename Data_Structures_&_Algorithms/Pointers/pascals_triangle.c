#include<stdio.h>
#include <stdlib.h>

/*
    In this case, we would need to utilize multi-dimensional array which would require pointers to pointers 
*/

int main(){
    int nrows = 3;
    int **pascals = (int **)malloc(nrows * sizeof(int *));

    pascals[0] = (int *)malloc(sizeof(int));
    pascals[0][0] = 1;

    pascals[1] = (int *)malloc(2 * sizeof(int));
    pascals[1][0] = 1;
    pascals[1][1] = 1;

    pascals[2] = (int *)malloc(3 * sizeof(int));
    pascals[2][0] = 1;
    pascals[2][1] = 2;
    pascals[2][2] = 1;

    int i;
    int j;
    for (i = 1; i < nrows + 1; i++){
        for (j = 0; j < i; j++){
            printf("%d", pascals[i-1][j]);
        }
        printf("\n");
    }
}
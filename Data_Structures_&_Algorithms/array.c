#include <stdio.h>

int main(){
    int arr[5];
    int i;

    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    for (i=0;i<5;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}
#include <stdio.h>

// first compile by typing in make file_name
// and then execute the file by typing ./filename

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
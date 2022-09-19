#include <math.h>
#include <stdio.h>

void insertionsort(int arr[], int length)
{
    int i,temp,j;
    for (i=1; i<length; i++){
        j = i-1;

        while (j >= 0 && arr[j] > arr[j+1]){
            temp = arr[j+1]; // Swapping
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void printArray(int arr[], int n) // Printing Array
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {23, 56, 2, 3, 77, 65, 3};
    int length = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr,length);
    printArray(arr, length);

    return 0;
}

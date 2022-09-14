#include <stdio.h>

int input[] = {1, 3, 5, 6, 7, 9, 11};
int number = 3;
int answer = 1;

int binarysearch(int input_array[], int number_to_find, int left, int right)
{
    int middle = (right + left) / 2;

    if (number_to_find == input_array[middle])
    {
        return middle;
    }

    else if (number_to_find > input_array[middle]){
        return binarysearch(input_array, number_to_find, middle+1, right);
    }

    else {
        return binarysearch(input_array, number_to_find, left, middle-1);
    }

    return -1; // Does not exist
}

int main()
{
    int length = sizeof(input) / sizeof(input[0]);
    int res = binarysearch(input, number, 0, length-1);
    if (res == -1){
        printf("The number does not exist.\n");
    }
    else if (res != answer){
        printf("Error detected!\n");
    }
    else {
        printf("The number is in the %d index.\n", res);
    }

    return 0;
}

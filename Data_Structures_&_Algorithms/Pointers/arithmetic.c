#include <stdio.h>

int main()
{
    int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i], &intarray[i]);

    int *intpointer = &intarray[3]; //point to the 4th element in the array
    printf("address: %p - has value %d\n", intpointer, *intpointer); //print the address of the 4th element

    intpointer -= 3; // will be moving back 3 spaces; translates to 3x4 bytes - 12 bytes since integer takes up 4 bytes
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    return 0;
}
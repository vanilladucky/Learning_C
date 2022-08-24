
#include<stdio.h>
int static_fun()
{
    static int count = 0;
    count++;
    return count;
}

int fun()
{
    int count = 0;
    count++;
    return count;
}

int main()
{
    printf("What happens when the count variable is static\n\n");
    printf("\t%d ", fun());
    printf("%d \n\n", fun());

    printf("What happens when the count variable is not static\n\n");
    printf("\t%d ", static_fun());
    printf("%d \n\n", static_fun());
    return 0;
}

#include <stdio.h>

int main(void)
{
    // Adding to pointers

    int a[5] = {11, 22, 33, 44, 55};

    int *p = &a[0];             // or `int *p = &a;` works just as well
    printf("%d\n", *p);         // Prints 11
    printf("%d\n", *(p + 1));   // Prints 22

    // We can iterate over the elements of an array like so:
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));   // Same as p[i] !
    }
}

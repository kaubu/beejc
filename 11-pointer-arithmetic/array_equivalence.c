// a[b] == *(a + b)
// 
// or, more accurately:
// E1[E2] is identical to (*((E1)+(E2)))

// The one big difference is that you can modify a pointer to point to a
// different address, but you can’t do that with an array variable. 

#include <stdio.h>

int main(void)
{
    int a[] = {11, 22, 33, 44, 55};

    int *p = a; // p points to the first element of a, 11

    // Print all elements of the array a variety of ways:

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);       // Array notation with a
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", p[i]);       // Array notation with p
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(a + i));   // Pointer notation with a
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i));   // Pointer notation with p
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", *(p++));     // Moving pointer p
        // printf("%d\n", *(a++))   // Moving array variable a — this errors!
    }
}

#include <stdio.h>

void add_one(int a)
{
    a++;
}

void add_one_ref(int *a)
{
    *a++;
}

// This code doesn't work… why? Suppose I'll find out.
int main()
{
    int my_number = 99;

    printf("my_number: %d\n", my_number);

    add_one(my_number);
    
    printf("add_one(my_number): %d\n", my_number);

    add_one_ref(&my_number);

    printf("add_one_ref(&my_number): %d\n", my_number);
}

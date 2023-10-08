#include <stdio.h>

int main()
{
    // Print numbers between 0 and 9, inclusive…

    // Using a while statement:

    int i = 0;
    while (i < 10)
    {
        printf("i is %d\n", i);
        i++;
    }

    // Do the same thing with a for loop:

    for (int i = 0; i < 10; i++)
    {
        printf("i is %d\n", i);
    }

    // You can use the comma operator to do multiple things in each clause of
    // the `for` loop!
    for (int i = 0, j = 999; i < 10; i++, j++)
    {
        printf("%d, %d\n", i, j);
    }

    // An empty for loop will run forever
    for (;;)
    {
        printf("I will print this forever again and again\n");
        printf("for all eternity until the heat-death of the universe.\n");

        printf("Or until you hit CTRL-C.\n");
    }
}
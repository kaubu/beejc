/* Hello World program */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;      // Holds signed integers, e.g. -3, -2, 0, 1, 10
    float f;    // Holds signed floating point numbers, e.g. -3.1415

    i = 2;      // Assigns the value 2 into the variable i
    f = 3.14;
    char *s = "Hello World!";   // char * (char pointer) is the string type

    printf("Hello World!\n");   // Actually do the work here
    printf("%s i = %d and f = %f!\n", s, i, f);

    bool x = true;

    if (x) {
        printf("x is true!\n");
    }
}
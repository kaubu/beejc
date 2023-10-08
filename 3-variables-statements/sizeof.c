/*
The `sizeof` operator tells you the size (in bytes) of a particular expression
(that may just be a single variable).

C has a special type to represent the return value of `sizeof`. It's `size_t`.
It's an unsigned integer type that can hold the bytes of anything you give to
`sizeof`.

Think of it as a value that represents a count.
*/

#include <stdio.h>

int main()
{
    int a = 999;

    // %zu is the format specifier for size_t

    printf("%zu\n", sizeof a);      // Prints 4 on my system
    printf("%zu\n", sizeof(2 + 7)); // Prints 4 on my system
    printf("%zu\n", sizeof 3.14);   // Prints 8 on my system

    // If you need to print out negative size_t values, use %zd

    /*
    Remember, it's the size in bytes of the *type* (size_type) of the
    expression, not the size of the express itself. That's why the size of
    `2+7` is the same as `a`, they're both of the type `int`.

    The parentheses are required around a type name
    */
    printf("%zu\n", sizeof(int));   // Prints 4 on my system
    printf("%zu\n", sizeof(char));  // Prints 1 on my system (and all systems)

    // sizeof is a compile-time operation
}
#include <stdio.h>

int main(void)
{
    // We've already seen some examples of initializing string variables with
    // string literals:
    // 
    //      char *s = "Hello World!";
    //      char s[] = "Goodbye World…";
    // 
    // But these two are subtly different.

    // This one is a pointer to a string literal
    char *s = "Hello World!";
    // If you try to mutate it with array notation, it is undefined behaviour
    // s[0] = 'z';

    // Declaring an array is different, this one is a mutable *copy* of the
    // string that we can change at will.
    char t[] = "Goodbye World!…";
    t[0] = 'z'; // no problem

    printf("%s\n", t);
}

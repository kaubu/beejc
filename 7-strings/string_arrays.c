/**
 * Another option to char pointers is char arrays
*/

#include <stdio.h>

int main(void)
{
    char s[12] = "Hello World!";

    // or, if we were properly lazy and wanted to have the compiler figure out
    // the length for us

    char t[] = "Goodbye world…";

    // You can use array notation to access characters in a string
    // This will work even if using a char* type.
    for (int i = 0; i < 12; i++)
    {
        printf("%c\n", s[i]);
    }
}

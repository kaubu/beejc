/*
The basic idea is that you take the sizeof the array, and then divide that by
the size of each element to get the length. For example, if an int is 4 bytes,
and the array is 32 bytes long, there must be room for 32/4 or
8 ints in there.
*/

#include <stdio.h>

int main(void)
{
    int x[12];  // 12 ints

    printf("%zu\n", sizeof x);                  // 48 total bytes
    printf("%zu\n", sizeof(int));               // 4 bytes

    printf("%zu\n", sizeof x / sizeof(int));    // 48/4 = 12 ints!
}

#include <stdio.h>      // For printf
#include <stdlib.h>     // For rand

int main(void)
{
    int r;

    do {
        r = rand() % 100;
        printf("%d\n", r);
    } while (r != 37);  // Repeat until 37 comes up
}
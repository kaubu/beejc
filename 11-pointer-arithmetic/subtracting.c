#include <stdio.h>

int my_strlen(char *s)
{
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0')
    {
        p++;
    }

    return p - s;
}

int main(void)
{
    printf("%d\n", my_strlen("Hello, World!")); // Prints "13"!
}

#include <stdio.h>

int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0')
    {
        count++;
    }

    return count;
}

int main(void)
{
    char *s = "I bloody well LOVE sausages!";

    printf("The string is %d bytes long.\n", my_strlen(s));
}

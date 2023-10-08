// You can't get string length with a builtin mechanic, as C doesn't track it
// You *can*, however, use the function `strlen()` from `<string.h>` to compute
// the length of any string in bytes.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello World!";

    printf("The string is %zu bytes long.\n", strlen(s));
}

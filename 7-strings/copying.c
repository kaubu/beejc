// Copying a string variable merely copys the pointer to the string
// To fully copy a string, use strcpy() from string.h

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Hello World!";
    char t[100];    // Each character is one byte, so plenty of room

    // This makes a copy of a string!
    // It looks like it's Intel `mov` syntax: dest, src
    strcpy(t, s);

    // We modify t
    t[0] = 'z';

    // And s remains unaffected because it's a different string
    printf("%s\n", s);

    // But t has changed
    printf("%s\n", t);
}

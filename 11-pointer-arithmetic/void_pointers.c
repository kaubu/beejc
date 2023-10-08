// Sometimes it’s useful to have a pointer to a thing *that you don’t know the
// type of*.

#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, void *src, int byte_count)
{
    // Convert void*s to char*s
    char *s = src, *d = dest;

    // Now that we have char*s, we can dereference and copy them
    while (byte_count--)
    {
        *d++ = *s++;
    }

    // Most of these functions return the destination, just in case that's
    // useful to the caller
    return dest;
}

int main(void)
{
    // Copying a string
    {
        char s[] = "Goats!";
        char t[100];

        my_memcpy(t, s, 7);    // Copy 7 bytes--including the NUL terminator!

        printf("%s\n", t);
    }
    
    // Copying ints
    {
        int a[] = {11, 22, 33};
        int b[3];

        my_memcpy(b, a, 3 * sizeof(int));  // Copy 3 ints of data

        printf("%d\n", b[1]);
    }

    // Conversion / coercion of void pointers
    {
        char a = 'X';

        void *p = &a;   // p points to the 'X'
        char *q = &a;   // q also points to the 'X'

        // printf("%c\n", *p); // Error, cannot dereference a void pointer
        printf("%c\n", *q);     // Prints "X"
    }
}

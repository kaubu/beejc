// The malloc() function accepts a number of bytes to allocate, and returns a
// void pointer to that block of newly-allocated memory.

// Since it’s a void*, you can assign it into whatever pointer type you want…
// normally this will correspond in some way to the number of bytes you’re
// allocating.

//  So… how many bytes should I allocate? We can use sizeof to help with that.
//  If we want to allocate enough room for a single int, we can use sizeof(int)
//  and pass that to malloc(). 

//  After we’re done with some allocated memory, we can call free() to indicate
//  we’re done with that memory and it can be used for something else. As an
//  argument, you pass the same pointer you got from malloc() (or a copy of
//  it). It’s undefined behavior to use a memory region after you free() it.

// Let’s try. We’ll allocate enough memory for an int, and then store something
// there, and the print it.

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // Allocate space for a single int (sizeof(int) bytes worth):
    int *p = malloc(sizeof(int));

    *p = 12;

    printf("%d\n", *p); // Print it: 12

    free(p);

    // *p = 3490;  // ERROR: Undefined behaviour! Use after free!

    // Now, in that contrived example, there’s really no benefit to it. We
    // could have just used an automatic int and it would have worked. But
    // we’ll see how the ability to allocate memory this way has its
    // advantages, especially with more complex data structures.

    // One more thing you’ll commonly see takes advantage of the fact that
    // sizeof can give you the size of the result type of any constant
    // expression. So you could put a variable name in there, too, and use
    // that. Here’s an example of that, just like the previous one:

    int *p2 = malloc(sizeof *p2);  // *p2 is an int, so same as sizeof(int)
}

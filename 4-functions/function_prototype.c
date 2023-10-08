#include <stdio.h>

int foo(void);  // This is a prototype!

int main(void)
{
    int i;

    // We can call foo() here before it's definition because the prototype has
    // already been declared above!

    i = foo();

    printf("%d\n", i);  // 3490
}

int foo(void)
{
    return 3490;
}
# BeeJ C Tutorial notes
[https://beej.us/guide/bgc/html/split/](https://beej.us/guide/bgc/html/split/)

## Notes

### 3 Variables and Statements

#### 3.2 Operators and Expressions

##### 3.2.7 The `sizeof` operator
The `sizeof` operator tells you the size (in bytes) of a particular expression
(that may just be a single variable).

C has a special type to represent the return value of `sizeof`. It's `size_t`.
It's an unsigned integer type that can hold the bytes of anything you give to
`sizeof`.

Think of it as a value that represents a count.

---

`sizeof` can be used as `sizeof {{variable}}` or `sizeof(expression)`:

```c
// %zu is the format specifier for size_t

printf("%zu\n", sizeof a);      // Prints 4 on my system
printf("%zu\n", sizeof(2 + 7)); // Prints 4 on my system
printf("%zu\n", sizeof 3.14);   // Prints 8 on my system
```

#### 3.3 Flow Control

##### 3.3.4 The for statement
You can use the comma operator to do multiple things in each clause of the
`for` loop!

```c
for (int i = 0, j = 999; i < 10; i++, j++)
{
    printf("%d, %d\n", i, j);
}
```

An empty for loop will run forever.

```c
for (;;)
{
    printf("I will print this forever again and again\n");
    printf("for all eternity until the heat-death of the universe.\n");

    printf("Or until you hit CTRL-C.\n");
}
```

### 4 Functions

#### 4.2 Function Prototypes
Prototypes can be used if we want to declare that a function exists without it
needing to be defined before it is actually used.

```c
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
```

### 5+11 Pointers

#### 5.1 Memory and Variables
To printf out the address of a pointer, use `%p`.

```c
#include <stdio.h>

int main(void)
{
    int i = 10;

    printf("The value of i is: %d\n", i);
    printf("And the address is: %p\n", (void *)&i);

    // %p expects the argument to be a pointer to void so we cast it to make
    // the compiler happy
}
```

### 6 Arrays

#### 6.2 Getting the Length of an Array
You take the sizeof the array, and then divide that by the size of each element
to get the length.

For example, if an int is 4 bytes, and the array is 32 bytes long, there must
be room for 32/4 or 8 ints in there.

```c
#include <stdio.h>

int main(void)
{
    int x[12];  // 12 ints

    printf("%zu\n", sizeof x);                  // 48 total bytes
    printf("%zu\n", sizeof(int));               // 4 bytes

    printf("%zu\n", sizeof x / sizeof(int));    // 48/4 = 12 ints!
}
```

#### 6.3 Array Initializers
You can initialize an array with constants ahead of time:

```c
#include <stdio.h>

int main(void)
{
    int i;
    int a[5] = {22, 37, 3490, 18, 95};

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
}
```

#### 6.6 Arrays and Pointers
Arrays are essentially pointers to the first element, with each successive
element being `sizeof(type)` bytes to the right in memory.

##### 6.6.1 Getting a Pointer to an Array
This is how we get a pointer to the first element of an array:

```c
#include <stdio.h>

int main(void)
{
    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0];  // p points to the array
                // Well, to the first element, actually

    printf("%d\n", *p);  // Prints "11"
}
```

This is so common to do in C that the language allows us a shorthand:

```c
p = &a[0];  // p points to the array

// is the same as:

p = a;      // p points to the array, but much nicer-looking!
```

##### 6.6.2 Passing Single Dimensional Arrays to Functions

Passing (single dimensional) arrays in as function arguments can be done in
three ways!

```c
#include <stdio.h>

// Passing as a pointer to the first element
void times2(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i] * 2);
    }
}

// Same thing, but using array notation
void times3(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i] * 3);
    }
}

// Array with a pre-set length
void times4(int a[5], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\n", a[i] * 4);
    }
}

int main(void)
{
    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);
}
```

##### 6.6.4 Passing Multidimensional Arrays to Functions
Passing multidimensional arrays is similar, but C needs to know all the
dimensions (except the first one) so it has enough information to know where in
memory to look to find a value.

Here’s an example where we’re explicit with all the dimensions:

```c
#include <stdio.h>

void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x);
}
```

But in this case, these two are equivalent:

```c
void print_2D_array(int a[2][3])
void print_2D_array(int a[][3])
```

### 7 Strings

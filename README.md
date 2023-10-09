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
To printf out the address of a pointer, use `%p` and typecast it to a void
pointer!

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
#### 7.2 String Variables
Declare strings using a char pointer.

```c
#include <stdio.h>

int main(void)
{
    char *s = "Hello World!";

    printf("%s\n", s);
}
```

#### 7.3 String Variables as Arrays
You can use also declare strings as an array.

```c
#include <stdio.h>

int main(void)
{
    char s[12] = "Hello World!";

    // or, if we were properly lazy and wanted to have the compiler figure out
    // the length for us

    char t[] = "Goodbye world…";

    // You can use array notation to access characters in a string
    // This will work even if using a char* type.
    for (int i = 0; i < 12; i++)
    {
        printf("%c\n", s[i]);
    }
}
```
#### 7.4 String Initializers
We've already seen some examples of initializing string variables with string
literals:

```c
char *s = "Hello World!";
char s[] = "Goodbye World…";
```

But these two are subtly different.

```c
#include <stdio.h>

int main(void)
{
    // This one is a pointer to a string literal
    char *s = "Hello World!";
    // If you try to mutate it with array notation, it is undefined behaviour
    // s[0] = 'z';

    // Declaring an array is different, this one is a mutable *copy* of the
    // string that we can change at will.
    char t[] = "Goodbye World!…";
    t[0] = 'z'; // no problem

    printf("%s\n", t);
}
```

#### 7.5 Getting String Length
You can get the string length in bytes by including the `string.h` header file,
which has the `strlen()` function.

```c
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
```

#### 7.7 Copying a String
You can deep copy a string by including the `string.h` header file and using
the `strcpy()` function.

```c
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
```

### 8 Structs
#### 8.1 Declaring a Struct
You can declare a struct like so:

```c
struct car {
    char *name;
    float price;
    int speed;
};
```

Initialize it and set its values like so:

```c
struct car saturn;  // Variable "saturn" of type "struct car"
saturn.name = "Saturn SL/2";
saturn.price = 15999.99;
saturn.speed = 175;
```

#### 8.2 Struct Initializers
Using our example for before, we can initialize a struct by setting all its
fields in the same order that it's declared in:

```c
struct car saturn = {"Saturn SL/2", 16000.99, 175};
```

Or, we can be more specific using the `.NAME=VALUE` syntax:

```c
struct car saturn = {.speed=175, .name="Saturn SL/2"};
```

#### 8.3 Passing Structs to Functions
Structs must (or should?) be passed as a pointer in functions.

Don't forget that to access a pointer's properties it's easier to use arrow
syntax `strct->value`.

```c
#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float price)
{
    // Works, but is ugly. Use the arrow operator.
    // (*c).price = price;

    // Proper way:
    c->price = price;
}

int main(void)
{
    struct car saturn = {.speed=175, .name="Saturn SL/2"};

    // Pass a pointer to this struct car, along with a new, more realistic
    // price:
    set_price(&saturn, 799.99);

    printf("Price: %f\n", saturn.price);
}
```

## 9 File Input/Output

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

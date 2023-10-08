// You can do a couple of things to pass a struct to a function:
// 1. Pass the struct
// 2. Pass a pointer to the struct

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

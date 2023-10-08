#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

int main(void)
{
    // Now with an initializer! Same field order as struct declaration:
    struct car saturn = {"Saturn SL/2", 16000.99, 175};

    printf("Name:       %s\n", saturn.name);
    printf("Price:      %f\n", saturn.price);
    printf("Top Speed:  %d km\n", saturn.speed);

    // We can be more specific with our initializers:
    struct car saturn = {.speed=175, .name="Saturn SL/2"};
}

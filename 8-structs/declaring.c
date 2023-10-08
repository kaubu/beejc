#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

int main(void)
{
    struct car saturn;  // Variable "saturn" of type "struct car"
    saturn.name = "Saturn SL/2";
    saturn.price = 15999.99;
    saturn.speed = 175;

    printf("Name:       %s\n", saturn.name);
    printf("Price:      %f\n", saturn.price);
    printf("Speed:      %d\n", saturn.speed);
}

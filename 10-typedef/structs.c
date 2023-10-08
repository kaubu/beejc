#include <stdio.h>

struct animal_a {
    char *name;
    int leg_count, speed;
};

//  original name      new name
//               |         |
//               v         v
//      |-------------| |-------|
typedef struct animal_a animal_a;

//  original name
//            |
//            v
//      |--------------|
typedef struct animal_b {
    char *name;
    int leg_count, speed;
} animal_b;                 // <-- new name

//  Anonymous struct! It has no name!
//         |
//         v
//      |----|
typedef struct {
    char *name;
    int leg_count, speed;
} animal_c;                 // <-- new name

typedef struct {
    int x, y;
} point;

int main(void)
{
    animal_c tiger;

    point p = {.x=20, .y=40};

    printf("%d, %d\n", p.x, p.y);
}

// You can initialize an array with constants ahead of time:

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

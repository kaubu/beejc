#include <stdio.h>

int main(void)
{
    FILE *fp;
    char name[1024];
    float length;
    int mass;

    fp = fopen("9-file-io/whales.txt", "r");

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
    {
        printf("%s whale, %d tons, %.1f metres\n", name, mass, length);
    }

    fclose(fp);
}

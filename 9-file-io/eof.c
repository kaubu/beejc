#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;

    fp = fopen("9-file-io/hello.txt", "r");

    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);
}

#include <stdio.h>

int main(void)
{
    FILE *fp;
    int x = 32;

    fp = fopen("9-file-io/output.txt", "w");
    // Since stdout is a file, doing the below will print out to the console
    // fp = stdout;

    fputc('B', fp);
    fputc('\n', fp);
    fprintf(fp, "x = %d\n", x);
    fputs("Hello World!\n", fp);
}

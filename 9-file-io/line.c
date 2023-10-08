#include <stdio.h>

int main(void)
{
    FILE *fp;
    char s[1024];   // A char buffer
    int line_count = 0;

    fp = fopen("9-file-io/quote.txt", "r");

    while (fgets(s, sizeof s, fp) != NULL)
    {
        printf("%d: %s", ++line_count, s);
    }

    fclose(fp);
}

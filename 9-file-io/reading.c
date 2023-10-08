#include <stdio.h>

int main(void)
{
    FILE *fp;                                   // Variable to represent open
                                                // file

    fp = fopen("9-file-io/hello.txt", "r");     // Open file for reading in a
                                                // stream

    int c = fgetc(fp);                          // Get a single character from 
    printf("%c\n", c);                          // a stream

    fclose(fp);                                 // Close the file when done
}

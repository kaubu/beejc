#include <stdio.h>

int main()
{
    // Print the following output:
    // 
    //      i is now 0!
    //      i is now 1!
    //      [ more of the same between 2 and 7 ]
    //      i is now 8!
    //      i is now 9!

    int i = 0;

    while (i < 10)
    {
        printf("i is now %d!\n", i);
        i++;
    }

    printf("All done!\n");
}
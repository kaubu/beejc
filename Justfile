# Compile and run the given file
run *file:
    gcc -Wall -Wextra -std=c2x -pedantic {{file}}
    ./a.out
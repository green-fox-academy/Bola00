#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE * my_file;
    my_file = fopen("my-file.txt", "w");
    fprintf(my_file, "Laci");
    return 0;
}
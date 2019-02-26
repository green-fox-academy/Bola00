#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{

    FILE *my_file;
    my_file = fopen("../my-file.txt", "r");
    if (my_file == NULL) {
        printf("Failed to open file");
        return 1;
    }

    char line[100];

    while (!feof(my_file)) {
        fgets(line, sizeof(line), my_file);
        printf("%s", line);
    }

    fclose(my_file);
    return 0;
}
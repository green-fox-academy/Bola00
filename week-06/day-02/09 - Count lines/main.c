#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file


int line_counter(char file_name[])
{
    FILE *my_file;
    my_file = fopen(file_name, "r");
    if (my_file == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    fseek (my_file, 0, SEEK_END);  //goes to the end of the file
    int size = ftell(my_file);
    if (size == 0) // if the end of the file is zero it means it's empty
        return 0;

    fseek (my_file, 0, SEEK_SET); // go back to the begining

    int counter = 1;
    while (!feof(my_file)) {
        char character = fgetc(my_file);
        if (character == '\n')
        counter++;

    }

    fclose(my_file);

    return counter;
}

int main()
{
    char file[] = "../my-file.txt";
    printf("%i", line_counter(file));
    return 0;
}
#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void write_file(char path[], char word[], int number)
{
    FILE *my_file;
    my_file = fopen(path, "w");

    int counter = 0;
    while (counter != number) {
        fprintf(my_file,"%s \n", word);
        counter++;
    }
    fclose(my_file);
}

int main()
{
    write_file("my-file.txt", "apple", 5);
    
    return 0;
}
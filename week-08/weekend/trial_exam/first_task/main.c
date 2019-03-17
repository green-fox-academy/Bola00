#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
char binary_to_character(char* binary_numbers)
{
    int ascii_value = 0;
    int checking_value = 1;
    for (int i = 7; i >= 0; i--){
        if (binary_numbers[i] == '1') {
            ascii_value += checking_value;
        }
        checking_value = checking_value << 1;

    }
    return ascii_value;
}

char* file_reading(char* file)
{
    FILE* my_file;
    my_file = fopen(file, "r");
    if (my_file == NULL) {
        printf("Failed to open file");
    }

    fseek (my_file, 0, SEEK_END);
    int size = ftell(my_file);
    fseek (my_file, 0, SEEK_SET);

    char* line = (char*) calloc (size, sizeof(char));
    fgets(line, size, my_file);

    char* token = strtok(line, " ");
    char* result = (char*) calloc (size/9+1, sizeof(char));
    result[0] =  binary_to_character(token);
    int counter = 1;
    while (counter != size/9){
        token = strtok(NULL, " ");
        result[counter] = binary_to_character(token);
        counter++;
    }
    result[counter] = '\0';
    free(line);
    fclose(my_file);
    return result;
}

int main(){

    char* file_path = "../text.txt";

    char* text = file_reading(file_path);

    printf("%s\n", text);
    free(text);
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

int count_lines (std::string File_name) {
int lines = 0;
    try {
        std::ifstream myFile;
        myFile.open(File_name);
        std::string line;
        while(std::getline(myFile, line))
        {lines++;}

    }catch (...){}
    return lines;
}

int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::string text = "text2.txt";

    std::cout << count_lines (text);

    return 0;
}
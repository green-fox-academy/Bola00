#include <iostream>
#include <fstream>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ifstream myFile;
    myFile.open("my-file.txt");
    std::string line;
    while(std::getline(myFile, line))
    {
        std::cout << line << std::endl;
    }
    myFile.close();

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

     std::ofstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        myFile.open("text.txt");
        std::string str = "Laszlo Bogar";
        myFile << str;
        myFile.close();

        return 0;
}

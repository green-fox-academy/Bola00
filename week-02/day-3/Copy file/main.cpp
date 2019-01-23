#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copy (std::string file1, std::string file2){
    try {
        std::ifstream myFile;
        myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        myFile.open(file1);

        std::ofstream myFile2;
        myFile2.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        myFile2.open(file2);

        std::string line;

        while (std::getline(myFile, line)) { //while myFile1 still has a line it goes and give the lines to the myFile2
            myFile2 << line << std::endl;
        }
        myFile.close();
        myFile2.close();
    }catch (...){}
}

int main() {

    std::string file1 ="text1.txt"; //path of the file1
    std::string file2 ="text2.txt"; //path of the file2


    std::cout << copy(file1, file2);

    return 0;
}
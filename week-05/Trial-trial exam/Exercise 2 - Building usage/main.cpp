#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

void sumEntrance(std::string input, std::string output)
{
    std::ifstream inputFile;
    std::ofstream outputFile;
    inputFile.open(input);
    outputFile.open(output);
    std::map<std::string, int> entrance;

    std::vector<std::string> types;

    try {
        if (!inputFile.is_open() || !outputFile.is_open()) // check the files are okay
            throw 99;

        std::string line;

        while (std::getline(inputFile, line)) { // goes through on the lines

            std::stringstream aLineStream(line);
            std::string word;
            int counter = 0;
            while (std::getline(aLineStream, word, ' ')) { //separate the line into words
                if (counter == 1) {
                    if (std::find(types.begin(), types.end(), word) == types.end()) { // if it's not a part of the known types, make it
                        types.push_back(word);
                        entrance[word] = 1;
                    } else {
                        entrance[word] += 1;
                    }
                }

                counter++;
            }
        }

        for (int i = 0; i < types.size(); i++){
            outputFile << types.at(i) << ": " << entrance[types.at(i)] << "\n";
        }

    } catch (int number) {
        std::cout << "One of the file is not open" << std::endl;
    }
    inputFile.close();
    outputFile.close();
}

int main()
{

    std::string inputFilePath = "../exam_input.txt";
    std::string outputFilePath = "../exam_output.txt";

    sumEntrance(inputFilePath, outputFilePath);
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

  // Create a function that takes 3 parameters: a path, a word and a number,
  // than it should write to a file.
  // The path parameter should describes the location of the file.
  // The word parameter should be a string, that will be written to the file as lines
  // The number paramter should describe how many lines the file should have.
  // So if the word is "apple" and the number is 5, than it should write 5 lines
  // to the file and each line should be "apple"



 void shot (std::string path, std::string word, int num){

     std::ofstream myFile;
     myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
     myFile.open(path);
     for (int i = 0; i < num; i++){
     myFile << word <<" ";
     }
     myFile.close();
}


int main() {

    std::string path_shot = "../shot.txt"; // path of the txt file
    std::string word = "shot";
    int num = 5;

    shot(path_shot, word, num);

    return 0;
}
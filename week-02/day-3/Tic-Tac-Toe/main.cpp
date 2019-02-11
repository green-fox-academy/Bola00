#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string ticTacResult (std::string file){

    std:: string result;
    std::ifstream myFile;
    myFile.open(file);
    std::string line;
    std::vector<char> places;
    while (std::getline(myFile, line)) {
        places.push_back(line[0]);
        places.push_back(line[1]);
        places.push_back(line[2]);
    }

      if (places[0] == places[1] && places[1]  == places[2]){
          result = places [0];
      }else if(places[3] == places[4] && places[4] == places[5]){
          result = places [3];
      }else if(places[6] == places[7] && places[7] == places[8]){
          result = places [6];
      }else if(places[1] == places[4] && places[4] == places[7]){
          result = places [1];
      }else if(places[0] == places[3] && places[3] == places[6]){
          result = places[6];
      }else if(places[2] == places[5] && places[5] == places[8]){
          result = places[5];
      }else if(places[0] == places[4] && places[4] == places[8]){
          result = places[0];
      }else if(places[2] == places[4] && places[4] == places[6]){
          result = places[4];
      }else { result = "draw";
      }

    myFile.close();

    return result;
}


int main() {
    // Write a function that takes a filename as string,
    // open and read it. The file data represents a tic-tac-toe
    // game result. Return 'X'/'O'/'draw' based on which player
    // has winning situation.

    std::cout << ticTacResult("win-o.txt") <<std::endl;
    // should print O

    std::cout << ticTacResult("win-x.txt")<<std::endl;
    // should print X

   std::cout << ticTacResult("draw.txt")<<std::endl;
    // should print draw

    return 0;
}
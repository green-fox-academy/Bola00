#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>
#include <algorithm>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector <std::string> unique_IPs (std::string file) {

    std::vector<std::string> temp; // temporary vector for the IPs

    std::ifstream myFile; //call and open the file
    myFile.open(file);
    std::string line;
    while (std::getline(myFile, line)) { //get over on every line

        std::istringstream line_stream(line);
        std::string token;
        char delimiter = ' ';

        int count = 0;

        while (std::getline(line_stream, token, delimiter)) { // take apart the line
            if (count == 8) {// on place 8 there is the IP
                if (std::find(temp.begin(), temp.end(), token) == temp.end()) // if the IP is not found in the vector it push back
                    temp.push_back(token);

            }
            count++;
        }
    }

    myFile.close();
    return temp;
}

std::string GET_POST(std::string file){
int get = 0;
int post = 0;

    std::ifstream myFile; // call and open the file
    myFile.open(file);
    std::string line;
    while (std::getline(myFile, line)) {

        std::istringstream line_stream(line); //go throw on the lines
        std::string token;
        char delimiter = ' ';

        int count = 0;

        while (std::getline(line_stream, token, delimiter)) { // take apart the line
            if (count == 11) {// get and post is on place 11
                if ( token == "GET"){
                    get++;
                }else if ( token == "POST"){
                    post++;
                }
            }count++;
            }
            }

   std::string result = std::to_string(get) + "/" + std::to_string(post); //make a string from the the ints
    myFile.close();
    return result;
            }

int main() {

    std::string file = "Log.txt"; //the path of the file

   std::vector <std::string> uniques = unique_IPs(file); //call uniques function and write out the vector's elements
   for (int i = 0; i < uniques.size(); i ++) {
       std::cout << i+1 << ". "<< uniques[i] << std::endl;

   }
    std::cout<< std::endl;
std::cout << "The GET and the POST ratio is " << GET_POST(file); // call GET_POST function and write out the string result

    return 0;
}
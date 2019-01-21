#include <iostream>
#include <string>

//std::string example("In a dishwasher far far away");
//example.replace("dishwasher", "galaxy");

// I would like to replace "dishwasher" with "galaxy" in this example, but it has a problem.
// Please fix it for me!
// Expected output: In a galaxy far far away

int main() {

    //the wrong sentence
std::string a = "In a dishwasher far far away";
std:: string from = "dishwasher";

    //a.find(from) - search in "a" sentence the string "from"
    int start_pos = a.find(from);
    if(start_pos == std::string::npos)//check that from is even in the sentence
        std::cout << "Cannot replace" << std::endl;
    else{
        a.replace(start_pos, from.length(), "galaxy");}
        //a.replace (the starting index, the long of the replace, the new string part)

    std::cout << a << std::endl;

    return 0;
}
#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed..

std::string stringManipulator (std::string a){
    if (a.size() == 1){// if the last letter is 'x', delete it
        if (a[0] == 'x'){
            a.clear();
        }
        return a;
    }else {
std::string first_letter = a.substr(0,1); // delete the first letter if it's an 'x'
        if (first_letter[0] == 'x'){
            first_letter.clear();
        }
    return (first_letter + stringManipulator(  a.substr(1, a.size() )  ) );
    }

}

int main() {

    std::string userInput;
    std::cout << "Write something nice: ";
    std::getline(std::cin, userInput);

    std::cout << stringManipulator(userInput);





    return 0;
}
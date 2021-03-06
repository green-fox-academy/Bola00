
#include <iostream>

// Given a string, compute recursively a new string where all the
// adjacent chars are now separated by a '*'.

std::string stringManipulator (std::string a){
    if (a.size() == 1){
        return a;
    }else {
        std::string first_letter = a.substr(0,1); 
            first_letter.push_back('*');
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
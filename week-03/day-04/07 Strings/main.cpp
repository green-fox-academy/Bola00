#include <iostream>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.

std::string stringManipulator (std::string a){
    if (a.size() == 1){
        if (a[0] == 'x'){
            a[0] = 'y';
        }
        return a;
    }else {
std::string first_letter = a.substr(0,1);
        if (first_letter[0] == 'x'){
            first_letter[0] = 'y';
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
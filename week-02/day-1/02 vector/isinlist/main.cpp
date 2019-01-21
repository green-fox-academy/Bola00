#include <iostream>
#include <vector>

bool checkNums(const std::vector<int> numbers, const std::vector<int> checker){

    //"i" = "checkers" index number
    int i = 0;

    //"count = it count the found "checker" values
    int count = 0;

    //main while goes on the checker
    while ( i < checker.size()){
        //"u" = "numbers" index number
        int u = 0;
        // second while check the actual "checker" index's number in "numbers" vector
        while ( (checker[i] != numbers[u] ) && (u < numbers.size() ) ){
            u++;
        }
            if ( u < numbers.size() ){

                //hit
                count ++;
            }
            i++;
    }
    return ( count == checker.size() ); //if it's true than all the "checker" are found in "numbers"
}

int main(int argc, char* args[])
{
    const std::vector<int> numbers = {2, 4, 6, 8, 10, 12, 14};
    const std::vector<int> numbers2 = {2, 4, 6, 8, 10, 12, 14, 16};
    const std::vector<int> checker = {4, 8, 12, 16};

    // Check if vector contains all of the following elements: 4,8,12,16
    // Create a method that accepts vector as an input
    // it should return "true" if it contains all, otherwise "false"

    // Expected output: "The first vector does not contain all the numbers"
    if (checkNums(numbers, checker)) {
        std::cout << "The first vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The first vector does not contain all the numbers" << std::endl;
    }

    // Expected output: "The second vector contains all the numbers"
    if (checkNums(numbers2, checker)) {
        std::cout << "The second vector contains all the numbers" << std::endl;
    } else {
        std::cout << "The second vector does not contain all the numbers" << std::endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> filter
    (const std::vector<std::string> list, const std::vector<std::string> sweets){

    //temporary vector
    std::vector<std::string> temp;

    for (int i = 0; i < list.size(); i++){ //it goes on the list

        for (int u = 0; u < sweets.size(); u++){ // goes on the sweets

            if ( list.at(i) == sweets.at(u) ){ // check that the current list element is
                                                // it equal to the the current sweet or not
                temp.push_back( list.at(i) ); // if they are the same, then add to the "temp" vector
            }
        }

    }
    return temp;
}


int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the two lists as parameters.

    std::vector<std::string> filteredList = filter(list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }

    return 0;
}
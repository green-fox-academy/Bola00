
#include <iostream>
#include <vector>


std::string containsSeven(const std::vector<int>& numbers)
{   // make a temporary vector for the numbers
    std::vector<int> temp(numbers);
    std::string output;

    //"i" is gonna be the index, while loop - goes until a value gonna be 7 or "i" is over the last index
    int i = 0;
    while ((temp[i] != 7) && (i != temp.size()) ) {i++;}

    //if "i" < than the size it means it find a number 7 in the vector
    if (i < temp.size()){
        output ="Hoorray";
    }
    else {output ="Noooooo";}
    return output;
}

int main(int argc, char* args[])
{
    const std::vector<int> numbers = {1, 2, 3, 4, 5};
    const std::vector<int> numbers2 = {6, 7, 8, 9, 10};

    // Write a method that checks if the vector contains "7" if it contains return "Hoorray" otherwise return "Noooooo"

    // Expected output: "Noooooo"
    std::cout << containsSeven(numbers) << std::endl;

    // Expected output: "Hoorray"
    std::cout << containsSeven(numbers2) << std::endl;

    return 0;
}
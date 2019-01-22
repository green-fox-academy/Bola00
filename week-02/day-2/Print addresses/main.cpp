#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int input_numbers[5];

    //user gives 5 numbers
    for (int i = 0; i < 5; i++){
        std::cout <<"give me a number: ";
        std::cin >>input_numbers[i];
    }

    //store the memory address of the first element of the array
    int* p_input_numbers = input_numbers;
    for (int i =0; i <5; i++){

        //print the memory addresses one by one
        std::cout << (p_input_numbers + i) << std::endl;
    }
    return 0;
}
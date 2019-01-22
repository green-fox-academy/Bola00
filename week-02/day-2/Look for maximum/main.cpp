#include <iostream>

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it


    // the user gives the long of the array
    int arr_lenght;
    std::cout << "How many numbers would you like to check? ";
    std::cin >> arr_lenght;


    int arr[arr_lenght];

    //the user gives the elements of the array
    for ( int i = 0; i < arr_lenght; i++ ){
        std::cout << "Number " << i+1 << ": ";
        std::cin >> arr[i];
    }

    int* biggest = &arr[0];

    for ( int i = 0; i <arr_lenght; i++ ){
        if ( *biggest < arr [i]){
            biggest = &arr[i];
        }
    }

    std::cout <<"Your biggest number is " << *biggest <<" and it's memmory address is " << biggest <<std::endl;

    return 0;
}
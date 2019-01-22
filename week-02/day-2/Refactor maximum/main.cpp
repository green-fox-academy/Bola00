#include <iostream>

int* search_maximum(int checking_numbers[], int size) {

    //at first we add the first value as a the biggest
    int *max = &checking_numbers[0];

    for (int i = 0; i < size; i++) {
        if (*max < checking_numbers[i]) {
            max = &checking_numbers[i];
        }
    }
    return max;
}

    int main()
{
    // Refactor time!
    // use your 'refactor_maximum.cpp', solve the same exercise by creating a separate function
    // for each functionality



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

    //first we add the biggest ponter the the first elment
    int* p_max = search_maximum(arr, arr_lenght);



    std::cout <<"Your biggest number is " << *p_max <<" and it's memmory address is " << p_max <<std::endl;


    return 0;
}
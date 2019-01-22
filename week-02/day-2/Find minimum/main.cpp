#include <iostream>

int* search_minimum(int checking_numbers[], int size){

    //at first we add the first value as a the smallest
    int* minimum = &checking_numbers[0];

    // then we check the numbers one by one is any of tham smaller the the minimum pointer's pointing value
    // if one is smaller change the pointers saved memmory address to the current numbers address
    for (int i = 0; i < size; i++){
        if ( *minimum > checking_numbers[i]){
            minimum = &checking_numbers[i];
        }
    }
return minimum;
}

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value


    int numbers[] = {12, 4, 66, 101, 87, 3, 15};    // it is the array what we check
    int numbers_lenght = sizeof(numbers)/ sizeof(numbers[0]); //the size of the array

    int* p_minimum = search_minimum(numbers, numbers_lenght);
    //search_minimum the funtcion which return the memmory address of the smallest number of array

    std::cout <<"Te smallest number is " << *p_minimum <<" and it's memmory address is " << p_minimum <<std::endl;

    return 0;
}
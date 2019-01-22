#include <iostream>
int search_number (int* arr, int arr_l, int x){


// search in the array the number until the lenght
// because 0 index is a value it needs -1
    int arr_place = -1;
    for (int i = 1; i <= arr_l; i++){
        if (arr[i-1] == x){
            arr_place += i;
        }
    }
    return arr_place;
}


int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0 (better it's gonna be -1)


    int arr [] = {4, 7, 9, 1, 5, 2, 8, 3};
    int arr_l = sizeof(arr)/sizeof(arr[0]);

    //user give the number what it gonna search in the array
    int num;
    std::cout<<"give me a number: ";
    std::cin >> num;

    // index gonna be the number of place index where it finds the "num"
    //needs -1 because index zero is a value too
     int index = search_number(arr, arr_l, num);

     //if its -1 the "num" number is not found in "arr" array
    std:: cout << index << std::endl;

    return 0;
}
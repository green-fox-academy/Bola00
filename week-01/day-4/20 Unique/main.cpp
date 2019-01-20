#include <iostream>
//  Create a function that takes a list of numbers as a parameter
//  Don't forget you have pass the size of the list as a parameter as well
//  Returns a list of numbers where every number in the list occurs only once

//  Example
//  int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
//std::cout << (std::unique(numbers)) << std::endl;
//  should print: `[1, 11, 34, 52, 61]`

int main() {

    //"n" gonna be the number of the elements
   int n;
    std::cout << "how many numbers would you check?: ";
    std::cin >> n;
    int nums[n] = {};


    //the user gives the list of numbers ->
    int i = 0;
    while (i < n){
       std::cout << "Give me a number: ";
       std::cin >> nums[i];
       i++;}


    std::cout << "your unique numbers: ";

    //check the numbers one by one
    for (int u = 0; u <n; u++) {
        int x = 0;

        // the while loop count with the "x" how much step can it takes before it find a same number as "u"
        while ( nums [x] != nums [u]){
            x++;

            // x == u means until "u" the checked number is unique
        }if ( x == u){
            std::cout << nums[u] << " ";
        }

    }

    return 0;
}

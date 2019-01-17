#include <iostream>

int main() {
    //18 Swap elements
    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`
    std::string abc [] ={"first", "second", "third"};
    std::string one = abc [0];
    abc [0] = abc [2];
    abc [2] = one;

    std::cout << "abc: ";
    for (int i = 0; i <(sizeof(abc)/sizeof(abc[0])); i++){
        std::cout<< abc[i] << ", ";
    }std::cout<<std::endl <<std::endl;

    //19 Sum all elements
    // - Create an array variable named `ai`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Print the sum of the elements in `ai`

    int ai [] = {3, 4, 5, 6, 7};
    int x = 0;
    for (int i = 0; i<(sizeof(ai))/(sizeof(ai[0])); i++){
        x += ai[i];
    }
    std::cout<< x << std::endl << std::endl;

    //20 Reverse list
    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj [] = {3, 4, 5, 6, 7};
    int ajn = sizeof(aj)/sizeof(aj[0]);
    int ja [] ={0,0,0,0,0};


    for (int i = 0; i<ajn; i++){
        ja [ajn-i-1] = aj[i];
    }

    for (int i = 0; i<ajn; i++){
     std::cout << ja[i] <<" ";
    }

    return 0;
}
#include <iostream>

int main() {
    //7 Third
    // - Create an array variable named `q`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print the third element of `q`

    int q []= {4, 5, 6, 7};
    std::cout << q[2] <<std::endl <<std::endl;

    //8 Compare Length
    // - Create an array variable named `p1`
    //   with the following content: `[1, 2, 3]`
    // - Create an array variable named `p2`
    //   with the following content: `[4, 5]`
    // - Print if `p2` has more elements than `p1`


    int p1[]= {1, 2, 3};
    int p2[]= {4, 5};
  int  pp1 = sizeof( p1 ) / sizeof( p1[ 0 ] );
  int  pp2 = sizeof( p2 ) / sizeof( p2[ 0 ] );

    std::cout<< bool(pp2 >pp1) <<std::endl;
    //or
    std::cout<< bool(sizeof(p2)> sizeof(p1)) <<std::endl <<std::endl;

    //9 Sum elements
    // - Create an array variable named `r`
    //   with the following content: `[54, 23, 66, 12]`
    // - Print the sum of the second and the third element

    int r [] = {54, 23, 66, 12};
    std::cout << (r[1]+r[2]) <<std::endl <<std::endl;

    //10 Change element
    // - Create an array variable named `s`
    //   with the following content: `[1, 2, 3, 8, 5, 6]`
    // - Change the 8 to 4
    // - Print the fourth element

    int s [] = {1, 2, 3, 8, 5, 6};
    s[3]=4;
    std::cout << s[3] <<std::endl <<std::endl;

    //11 Increment element

    // - Create an array variable named `t`
    //    with the following content: `[1, 2, 3, 4, 5]`
    // - Increment the third element
    // - Print the third element

    int t[]= {1, 2, 3, 4, 5};
    t[2]++;
    std::cout << t[2] <<std::endl <<std::endl;

    //12 Print elements
    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

int numbers [] = {4, 5, 6, 7};
for (int i = 0; i <4; i++){
        std::cout << numbers[i] << std::endl;
}

    return 0;
}
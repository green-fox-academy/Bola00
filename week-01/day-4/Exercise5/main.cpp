#include <iostream>

void factorio( int a , int& c){
    int x=1;
    for (int i = 1; i <=a; i++) {
        x*= i;}
    c = x;

}

int main() {
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int a;
    int b;
    std::cout<<"Give me a number: ";
    std::cin >> a;

    factorio(a, b);
    std::cout <<b <<std::endl;
    return 0;
}
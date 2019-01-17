#include <iostream>

void factorio(int& c){
    int x=1;
    for (int i = 1; i <=c; i++) {
        x*= i;}
    c = x;

}

int main() {
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int a = 3;
    factorio(a);
    std::cout <<a <<std::endl;
    return 0;
}
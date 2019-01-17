#include <iostream>

void sum(int y){
    int x=1;
    for (int i = 1; i <=y; i++) {
        x += i;
    }
     std::cout<< x << std::endl;
}

int main() {
   // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

int c = 10;
    sum(c);
    return 0;
}
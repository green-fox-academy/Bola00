#include <iostream>

int doubles (int x){
    x *= 2;
   std::cout << x << std::endl;
}

int main() {
    // Doubling exercise
    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    int baseNum = 123;
    doubles (baseNum);

    return 0;
}
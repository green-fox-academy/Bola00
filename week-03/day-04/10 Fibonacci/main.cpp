#include <iostream>

// The fibonacci sequence is a famous bit of mathematics, and it happens to
// have a recursive definition. The first two values in the sequence are
// 0 and 1 (essentially 2 base cases). Each subsequent value is the sum of the
// previous two values, so the whole sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21
// and so on. Define a recursive fibonacci(n) method that returns the nth
// fibonacci number, with n=0 representing the start of the sequence.
int fibonacciNumber (int n){
   if ( n == 0 ){
       return 0;
   }else if ( n == 1){
       return 1;
   }else{
       return (fibonacciNumber(n-1) + fibonacciNumber(n-2));
   }
}

int main() {

    int userInput;

    std::cout <<"Number: ";
    std::cin >> userInput;

    std::cout << fibonacciNumber(userInput);
    return 0;
}
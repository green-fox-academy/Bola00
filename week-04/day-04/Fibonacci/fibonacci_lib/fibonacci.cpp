//
// Created by bolar on 2019. 02. 07..
//

#include "fibonacci.h"

int Fibonacci::fibonacciNumber(int n)
{
    try {
        if (n < 0) {
            throw 99;
        }

        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return (Fibonacci::fibonacciNumber(n - 1) + Fibonacci::fibonacciNumber(n - 2));
        }
    }catch (...)
    {
        return 0;
    }
}
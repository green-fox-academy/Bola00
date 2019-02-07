//
// Created by bolar on 2019. 02. 07..
//

#include "fibonacci.h"
#include <gtest/gtest.h>

TEST(testingFibonacci, itIsZerro)
{
    ASSERT_EQ(Fibonacci().fibonacciNumber(0), 0);
}

TEST(testingFibonacci, itIsOne)
{
    ASSERT_EQ(Fibonacci().fibonacciNumber(1), 1);
}

TEST(testingFibonacci, itISAPozitivNumber)
{
    ASSERT_EQ(Fibonacci().fibonacciNumber(6), 8);
}


TEST(testingFibonacci, itIsNegativ)
{
    ASSERT_EQ(Fibonacci().fibonacciNumber(-1), 0);
}
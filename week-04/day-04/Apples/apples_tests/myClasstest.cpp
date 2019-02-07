//
// Created by bolar on 2019. 02. 07..
//

#include <gtest/gtest.h>
#include "myClass.h"

TEST(testApples, getApple)
{
    ASSERT_EQ(myClass().getApple(), "apple");

}

TEST(testsum, sumIsOkay)
{   std::vector<int> test = {1, 2, 3, 9};

    ASSERT_EQ(myClass().sum(test), 15);

}

TEST(testsum, nothingToSum)
{std::vector<int> test;
    ASSERT_EQ(myClass().sum(test), 0);
}

TEST(testsum, oneElement)
{std::vector<int> test = {5};
    ASSERT_EQ(myClass().sum(test), 5);
}

TEST(testsum, negativNums)
{std::vector<int> test = {-4, -1};
    ASSERT_EQ(myClass().sum(test), -5);
}
//
// Created by bolar on 2019. 02. 07..
//

#include <gtest/gtest.h>
#include "myClass.h"

TEST(testApples, getApple)
{
    ASSERT_EQ(myClass().getApple(), "apple");

}
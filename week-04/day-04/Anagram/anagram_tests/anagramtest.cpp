//
// Created by bolar on 2019. 02. 07..
//

#include "anagram.h"
#include <gtest/gtest.h>

TEST(testingAnagram, Itisanagram)
{
    EXPECT_EQ(Anagram().anagramCheck("kakas", "kaksa"), true);

}

TEST(testingAnagram, secondIsLonger)
{
    EXPECT_EQ(Anagram().anagramCheck("kakas", "kaksakasa"), false);

}

TEST(tesingAmagram,  secondIsLower)
{
    EXPECT_EQ(Anagram().anagramCheck("kakas", "kas"), false);

}


//
// Created by bolar on 2019. 02. 07..
//

#include "anagram.h"
#include <gtest/gtest.h>

TEST(testingAnagram, Itisanagram)
{

    ASSERT_EQ(Anagram().anagramCheck("saras"), true);
}

TEST(testingAnagram, Itisnotanagram)
{

    ASSERT_EQ(Anagram().anagramCheck("barka"), false);
}
//
// Created by bolar on 2019. 02. 07..
//

#include "countingLetters.h"
#include <gtest/gtest.h>
#include <map>

TEST(TestingLetterCounter, EverythingIsGood)
{
    std::map <char, int> charDiary = CountingLetters().characterCounting("bakancslista");
ASSERT_EQ(charDiary['a'], 3);

}

TEST(TestingLetterCounter, ItShouldBeTheSame)
{
    std::map <char, int> charDiary;
    charDiary.insert(std::make_pair('a', 1));
    charDiary.insert(std::make_pair('p', 2));
    charDiary.insert(std::make_pair('l', 1));
    charDiary.insert(std::make_pair('e', 1));

    ASSERT_EQ(CountingLetters().characterCounting("apple"), charDiary);

}
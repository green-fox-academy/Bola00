//
// Created by bolar on 2019. 02. 07..
//

#include <gtest/gtest.h>
#include "extansion.h"

TEST(add, _2and3is5) {
    ASSERT_EQ(5, Extansion().add(2, 3));
}

TEST(add, _1and4is5) {
    ASSERT_EQ(5, Extansion().add(1, 4));
}

TEST(max_of_three, first) {
    ASSERT_EQ(5, Extansion().maxOfThree(5, 4, 3));
}

TEST(max_of_three, second) {
    ASSERT_EQ(10, Extansion().maxOfThree(5, 10, 3));
}

TEST(max_of_three, third) {
    ASSERT_EQ(5, Extansion().maxOfThree(3, 4, 5));
}

TEST(median, four) {
    ASSERT_EQ(5, Extansion().median({7, 5, 3, 5}));
}

TEST(median, five) {
    ASSERT_EQ(3, Extansion().median({1, 2, 3, 4, 5}));
}

TEST(median, three) {
ASSERT_EQ(5, Extansion().median({5, 0, 10}));
}

TEST(is_vowel, a) {
    ASSERT_TRUE(Extansion().isVowel('a'));
}

TEST(is_vowel, u) {
    ASSERT_TRUE(Extansion().isVowel('u'));
}

TEST(is_vowel, k){
    ASSERT_FALSE(Extansion().isVowel('k'));
}

TEST(translate, bemutatkozik) {
    ASSERT_EQ("bevemuvutavatkovozivik", Extansion().translate("bemutatkozik"));
}

TEST(translate, lagopus) {
    ASSERT_EQ("lavagovopuvus", Extansion().translate("lagopus"));
}

TEST(translate, kacsa) {
    ASSERT_EQ("kavacsava", Extansion().translate("kacsa"));
}
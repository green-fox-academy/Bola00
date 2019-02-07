//
// Created by bolar on 2019. 02. 07..
//

#include "extansion.h"
#include <algorithm>
#include <sstream>

int Extansion::add(int a, int b)
{
    return a+b;
}

int Extansion::maxOfThree(int a, int b, int c)
{
    if (b < a && a > c)
        return a;
    else if(a < b && b > c)
        return b;
    else if (a < c && c > b)
        return c;
}

int Extansion::median(const std::vector<int>& pool) {
    int sum = 0;
    for (int i = 0; i < pool.size(); i++)
        sum += pool.at(i);
    return sum/pool.size();

}

bool Extansion::isVowel(char c) {
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::string Extansion::translate(const std::string hungarian)
{   std::string teve;
    int textLong = hungarian.size();
    for (int i = 0; i <textLong; i++){
        if (isVowel(hungarian.at(i)))
            teve = teve + hungarian.at(i) + "v" + hungarian.at(i);
        else
            teve = teve + hungarian.at(i);
    }
    return teve;
}

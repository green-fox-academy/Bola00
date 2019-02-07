//
// Created by bolar on 2019. 02. 07..
//

#ifndef APPLES_MYCLASS_H
#define APPLES_MYCLASS_H
#include <string>
#include <vector>

class Extansion
{
public:
    int add(int a, int b);
    int maxOfThree(int a, int b, int c);
    int median(const std::vector<int> &pool);
    bool isVowel(char c);
    std::string translate(const std::string hungarian);

};

#endif //APPLES_MYCLASS_H

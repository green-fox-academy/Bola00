//
// Created by bolar on 2019. 02. 07..
//

#include "countingLetters.h"

std::map<char, int> CountingLetters::characterCounting(std::string text)
{
    std::map <char , int > temp;
    for (int i = 0; i < text.size(); i++){
        if (temp.find(text.at(i)) != temp.end() ){
            temp[text.at(i)] += 1;
        } else temp.insert(std::make_pair(text.at(i), 1));
    }
    return temp;
}

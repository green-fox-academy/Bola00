//
// Created by bolar on 2019. 02. 07..
//

#include "anagram.h"

bool Anagram::anagramCheck(std::string text)
{
    int stringSize = text.size();
    std::string reverse;

    for (stringSize -= 1; stringSize >= 0; stringSize--){
        reverse+= text[stringSize];}

    return (text == reverse);
}

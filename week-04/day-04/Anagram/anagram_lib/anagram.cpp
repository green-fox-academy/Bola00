//
// Created by bolar on 2019. 02. 07..
//

#include "anagram.h"

bool Anagram::anagramCheck(std::string text, std::string text2) {
    bool answer = true;
    std::vector<char> chars;
    std::map<char, int> temp;
    for (int i = 0; i < text.size(); i++) {
        if (temp.find(text.at(i)) != temp.end()) {
            temp[text.at(i)] += 1;
        } else {
            temp.insert(std::make_pair(text.at(i), 1));
            chars.push_back(text.at(i));
        }
    }
    std::map<char, int> temp2;
    for (int i = 0; i < text2.size(); i++) {
        if (temp2.find(text2.at(i)) != temp2.end()) {
            temp2[text2.at(i)] += 1;
        } else temp2.insert(std::make_pair(text2.at(i), 1));
    }

    if(temp.size() == temp2.size()){
        for (int i = 0; i < chars.size(); i++) {
            char actualChar = chars.at(i);
            if (temp[actualChar] != temp2[actualChar])
                answer = false;
        }

    }else if (temp.size() != temp2.size()){
        answer = false;
    }
    return answer;
}

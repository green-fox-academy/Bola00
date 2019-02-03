#include <iostream>
#include <vector>
#include <string>

int subStrList (std::string looking, std::vector<std::string> words){
    int findingPlace = -1;

    for (int i = 0; i < words.size() ; ++i) {
        if (words.at(i).find(looking) != std::string::npos){
            findingPlace = i;
            goto End;
        }
    }
    End:
    return findingPlace;
}


int main(){

    //  Create a function that takes a string and a vector of string as a parameter
    //  Returns the index of the string in the vector where the first string is part of
    //  Only need to find the first occurence and return the index of that
    //  Returns `-1` if the string is not part any of the strings in the vector

    std::vector<std::string> searchArr = {"this", "is", "what", "I'm", "searching"};

    std::cout << subStrList("ching", searchArr) << std::endl;
    std::cout << subStrList("not", searchArr) << std::endl;


    return 0;
}
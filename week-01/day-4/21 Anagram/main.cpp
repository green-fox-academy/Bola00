#include <iostream>
//Create a function named is anagram following your current language's style guide.
// It should take two strings and return a boolean value
// depending on whether its an anagram or not.
int main() {

    //the user give the words
    std::cout<<"Show me an anagram!";
    std::string x;
    std::cout<< "give me a word: ";
    std::cin >> x;

    std::string y;
    std::cout<< "give me another word: ";
    std::cin >> y;

    // check the size of "x" string
    int xs = x.size();

    //it's gonna be reverse of x
    std::string xx;


    //new (empty) word + the one character of the word from the last till the first
    //-1 needs because the first character is on index zero and so on.
    for (xs -= 1; xs >= 0; xs--){
        xx+= x[xs];}

    std::cout << bool (xx == y);


    return 0;
}
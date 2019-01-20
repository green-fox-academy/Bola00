#include <iostream>
 //Create a function named create palindrome following
    //your current language's style guide. It should take a string,
    // create a palindrome from it and then return it.
int main() {

    //user give a word
    std::string d;
    std::cout <<"give me a word and I make it palindrome! (whatever it means)" << std::endl <<"Word: ";
    std:: cin >> d;

    // check the size of the string
   int x = d.size();

    //word + the one character of the word from the last till the first
    //-1 needs because the first character is on index zero and so on.
    for (x -= 1; x >= 0; x--){
        d+= d[x];

    }
    std::cout << d <<std::endl;


     return 0;
}
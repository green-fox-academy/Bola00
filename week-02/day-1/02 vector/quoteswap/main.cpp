#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> quoteSwap(std::vector<std::string> quote ) {


    quote.at(2).swap( quote.at(5) ); // swap two elements' place in vector

    return quote;
}

int main(int argc, char* args[]) {
    std::vector<std::string> quote = {"What", "I", "do", "create,", "I", "cannot", "not", "understand."};

    // Accidentally I messed up this quote from Richard Feynman.
    // Two words are out of place
    // Your task is to fix it by swapping the right words with code
    // Create a method called quoteSwap().

    // Also, print the sentence to the output with spaces in between.


    quoteSwap(quote);

    // write out the sentense word by word
    for (int i = 0; i < quoteSwap(quote).size(); i++){
        std::cout << quoteSwap(quote).at(i) << " ";
    }
    return 0;
}
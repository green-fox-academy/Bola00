#include <iostream>

int main() {
    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

for( int i = 1; i<=8; i++){
    for (int u =0; u<8; u++){
        if((u + i) % 2 == 1 ){
            std::cout<<"%";
        }else {std::cout<<" ";}
    }std::cout<<std::endl;
}
    return 0;
}
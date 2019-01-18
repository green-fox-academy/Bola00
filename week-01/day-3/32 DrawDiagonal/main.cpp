#include <iostream>

int main() {
    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    int a;
    std::cout << "A square for a number?" << std::endl << "Number: ";
    std::cin >> a;
    std::cout<<"Square:" <<std::endl;
    for (int i = 1; i<=a; i++){
        if (i == 1 || i == a){
            for (int u = 0; u < a; u++){
                std::cout<<"%";
            }
        }
        else {
            for(int k = 1; k<=a; k++){
                if (k == 1 || k == a){
                    std::cout<<"%";
                }else if (k == i) {
                    std::cout << "%";
                }else {std::cout<<" ";}
            }
        }
        std::cout << std::endl;

    }
    return 0;
}
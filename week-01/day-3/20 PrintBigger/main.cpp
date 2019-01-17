#include <iostream>

int main() {
    // Write a program that asks for two numbers and prints the bigger one
    int a;
    int b;
    std::cout<<"give me a number!";
    std::cin>>a;
    std::cout<<"give me another number!";
    std::cin>>b;

    if (a>b){
        std::cout << a <<" is the bigger"<<std::endl;
    }else if(a<b){
        std::cout << b <<" is the bigger"<<std::endl;
    }else if (a == b){
        std::cout <<" I asked another number NOT the same one!";
    }
    return 0;
}
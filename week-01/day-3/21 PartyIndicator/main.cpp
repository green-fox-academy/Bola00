#include <iostream>

int main() {
    // Write a program that asks for two numbers
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    // It should print: The party is excellent!
    // If the the number of girls and boys are equal and 20 or more people are coming to the party
    //
    // It should print: Quite cool party!
    // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
    //
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people

    int girls;
    int boys;

    std::cout<< " You make a party? WOW!"<<std::endl;
    std::cout<< "Number of girls? ";
    std::cin>>girls;
    std::cout<<"Number of boys?" ;
    std::cin>>boys;

    if (girls == 0){
        std::cout <<" AHA! I knew it gonna be a Sausege party!"<<std::endl;
    }       else if ((boys + girls) >=20){
                 if (boys == girls){
                 std::cout<< "The party is excellent!" <<std::endl;
                 }else{
                  std::cout<< "Quite cool party!" <<std::endl;
                   }
            }else {
        std::cout<< "Average party..." <<std::endl;
        }

    return 0;
}
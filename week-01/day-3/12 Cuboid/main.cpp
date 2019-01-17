#include <iostream>

int main() {
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double a;
    double b;
    double c;

    std::cout<< "give me the first side of the cuboid: ";
    std::cin>>a;
    std::cout <<std::endl;
    std::cout<< "give me the second side of the cuboid: ";
    std::cin>>b;
    std::cout <<std::endl;
    std::cout<< "give me the third side of the cuboid: ";
    std::cin>>c;
    std::cout <<std::endl;

    std::cout << "the cuboid area is " <<2 * ( a*b + a*c + b*c)<<std::endl;
    std::cout << "the cuboid volume is " << a * b * c <<std::endl;
}
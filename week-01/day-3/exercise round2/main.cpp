#include <iostream>

int main() {
    std::cout << "Bogár László" <<std::endl;
    std::cout << "23" <<std::endl;
    std::cout << "1,8m" <<std::endl <<std::endl;

    int a = 22;
    int b = 13;

    std:: cout << a + b <<std::endl;
    std:: cout << a - b <<std::endl;
    std:: cout << a * b <<std::endl;
    std:: cout << (float) a / b <<std::endl;
    std:: cout << a / b <<std::endl;
    std:: cout << a % b <<std::endl;

    int ch = 6;
    int sem = 17;

    std:: cout << "An attendee spends " << ch * 5 * sem << " hours whith coding in a semester."<<std::endl;
    std:: cout << "An attendee spends " << (float)(ch * 5 * sem) / (52 * 17) *100 << " percentage of the working hours with coding in a semester."<<std::endl;
    return 0;
}
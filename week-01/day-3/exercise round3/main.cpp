#include <iostream>

int main() {
    //07 favourite number
    int MFN = 12;
    std::cout <<"My favourite number is: " << MFN << std::endl << std::endl;
    //08 swap
    int a = 8;
    int b = 11;

    std::cout << a << std::endl;
    std::cout << b << std::endl << std::endl;
    //10 DefineBasicInfo

    std:: string name = "Laci";
    int age = 23;
    double height = 1.80;
    bool married = false;

    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;
    std::cout << married << std::endl << std::endl;

    //11 VariableMutation

    int ab = 3;
    // make the "ab" variable's value bigger by 10
    ab+= 10;
    std::cout << ab << std::endl;

    int ba = 100;
    // make ba smaller by 7
    ba-= 7;
    std::cout << ba << std::endl;

    int c = 44;
    // please double c's value
    c*=2;
    std::cout << c << std::endl;

    int d = 125;
    // please divide by 5 d's value
    d/=5;
    std::cout << d << std::endl;

    int e = 8;
    // please cube of e's value
    e*=e * e;
    std::cout << e << std::endl;

    int f1 = 123;
    int f2 = 345;
// tell if f1 is bigger than f2 (print as a boolean)

    std::cout << bool(f1 > f2)<<std::endl;

    int g1 = 350;
    int g2 = 200;
    // tell if the double of g2 is bigger than g1 (print as a boolean)
    std::cout << bool(g2*2 > g1)<<std::endl;

    int h = 135798745;
    // tell if it has 11 as a divisor (print as a boolean)
    std::cout << bool(h%11 == 0)<<std::endl;

    int i1 = 10;
    int i2 = 3;
    // tell if i1 is higher than i2 squared and smaller than i2 cubed (print as a boolean)
std::cout << bool( i2 * i2 < i1 < i2 * i2 * i2) << std::endl;

    int j = 1521;
    // tell if j is dividable by 3 or 5 (print as a boolean)
    std::cout << bool( j/3 ==0 || j/5==0) << std::endl;

    std::string k = "Apple";
    //fill the k variable with its content 4 times
    k=k+k+k+k;
    std::cout << k << std::endl;

    return 0;
}
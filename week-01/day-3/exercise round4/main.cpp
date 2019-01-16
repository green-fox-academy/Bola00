#include <iostream>

    int main(int argc, char* args[]) {
        //13 SecondsInADay
    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    int currentall = (currentHours*60*60 + currentMinutes*60 + currentSeconds);
    int allsecond =(24*60*60);
     int remainingseconds = allsecond - currentall;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

std::cout <<remainingseconds <<std::endl;

//14 HelloUser
// Modify this program to greet user instead of the World!
        // The program should ask for the name of the user
        std::string name;
        std::cout << "Please enter your name: ";
        std::cin >>name;
        std::cout << "Hello " << name <<"!" <<std::endl;

    //15 MileToKmConverter
        // Write a program that asks for an integer that is a distance in kilometers,
        // then it converts that value to miles and prints it

        int km;
        std::cout << "Write a number for a km: ";
        std::cin >> km;

        double miles =km * 0.62;
        std::cout << "This km is " << miles << " miles" <<std::endl;



        return 0;
}
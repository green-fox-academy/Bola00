#include <iostream>
#include "PostIt.h"
//Create a PostIt class that has
//a backgroundColor
//a text on it
//a textColor
//Create a few example post-it objects:
//an orange with blue text: "Idea 1"
//a pink with black text: "Awesome"
//a yellow with green text: "Superb!"

int main() {
   PostIt one ("Idea 1", "orange", "blue");
   PostIt two ("Awesome", "pink", "black");
   PostIt three ("Superb!", "yellow", "green");

   std::cout << two.backGroundColor;
}
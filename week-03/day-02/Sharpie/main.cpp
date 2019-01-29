#include <iostream>
//Create Sharpie class
//We should know about each sharpie their color (which should be a string),
// width (which will be a floating point number), inkAmount (another floating point number)
//When creating one, we need to specify the color and the width
//Every sharpie is created with a default 100 as inkAmount
//We can use() the sharpie objects
//which decreases inkAmount

class Sharpie {
public:
    std::string color;
    float width;
    float inkAmount;

    Sharpie (){
        inkAmount = 100;
    }

void sharpie (std::string obcolor, float obwidth){
        color = obcolor;
        width = obwidth;
    }

    void use(){
        inkAmount--;
    }
};


int main() {
   Sharpie Sh_one;
   Sh_one.sharpie("orange", 2.43);
   Sh_one.use();

   return 0;
}
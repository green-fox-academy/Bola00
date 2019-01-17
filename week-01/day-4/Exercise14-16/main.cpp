#include <iostream>

int main() {
    // 14 Double items
      // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array

    int numList[] ={3,4,5,6,7};
    for (int i=0; i<(sizeof(numList)/sizeof(numList[0])); i++){
        numList[i]*=2;
    }
    for (int i = 0; i <sizeof(numList)/sizeof(numList[0]); i++) {
        std::cout << numList[i]<<" ";
    } std::cout<< std::endl;
    std::cout<< std::endl;


    //15 Colors
    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`

    std::string greens[] = {"lime", "forest green", "olive", "pale green", "spring green"};
    std::string reds[] ={"orange red", "red", "tomato"};
    std::string pink[] ={"orchid", "violet", "pink", "hot pink"};
    std::cout << "Greens: ";
    for (int i = 0; i <sizeof(greens)/sizeof(greens[0]); i++) {
        std::cout << greens[i]<<", ";
    }
    std::cout<< std::endl;
    std::cout << "Reds: ";
    for (int i = 0; i <sizeof(reds)/sizeof(reds[0]); i++) {
        std::cout << reds[i]<<", ";
    }
    std::cout<< std::endl;
    std::cout << "Pink: ";
    for (int i = 0; i <sizeof(pink)/sizeof(pink[0]); i++) {
        std::cout << pink[i]<<", ";
    }

    std::cout<< std::endl;
    std::cout<< std::endl;

    //16 Append a
    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals[] = {"koal", "pand", "zebr"};
    for (int i = 0; i <sizeof(animals)/sizeof(animals[0]); i++) {
        animals[i] +="a";
    }
    std::cout << "Animals: ";
    for (int i = 0; i <sizeof(animals)/sizeof(animals[0]); i++) {
        std::cout << animals[i] << ", ";
    }
    return 0;

}
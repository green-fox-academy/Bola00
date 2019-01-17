#include <iostream>

int main() {
    //13 Matrix
    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    int sas[4][4] ={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    for(int i = 0; i<4; i++){
        for(int h = 0; h<4; h++){
            std::cout<< sas[i][h] <<" ";
        }std::cout<<std::endl;
    }

   return 0;
}

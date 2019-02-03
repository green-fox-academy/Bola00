#include <iostream>
#include <vector>

std::vector<int> subInt(int search, std::vector<int>numbers)
{
    std::vector<int> counter;
    int a = 0;

  for (int i = 0; i < numbers.size(); i ++){
      while (numbers.at(i) != 0){
      if (numbers.at(i) % 10 == search){
          counter.push_back(i);
          a++;
          goto otherNumber;
      }else{
          numbers.at(i) /= 10;
      }
      }
      otherNumber: ;
  }
    return counter;
}


int main(int argc, char* args[])
{
    //  Create a function that takes a number and a vector of numbers as a parameter
    //  Returns the indeces of the numbers in the vector where the first number is part of
    //  Returns an empty list if the number is not part any of the numbers in the vector

    //  Example:
 //   std::vector<int> numbers = {1, 11, 34, 52, 61};
//    subInt(1, numbers);
    //  should print: `[0, 1, 4]`
 //   subInt(1, numbers);
    //  should print: '[]'

    std::vector<int> numbers = {1, 11, 34, 52, 61};

    int lookingNumber = 1;

    std::vector<int> numberIndex =  subInt(lookingNumber, numbers);

    std::cout << "[ ";
    for ( int i = 0; i < numberIndex.size(); i++){
        std::cout << numberIndex.at(i) << ", ";
    }

    std::cout << "]";
    return 0;
}
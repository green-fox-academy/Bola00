#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int* p_a = &a;
    int* p_b = &b;

    int ab = (*p_a) + (*p_b);

    std::cout << ab;

    return 0;
}
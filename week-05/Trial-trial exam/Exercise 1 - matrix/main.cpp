#include <iostream>
#include <vector>

std::vector<std::vector<int>> biggerValue(std::vector<std::vector<int>> vector1, std::vector<std::vector<int>> vector2)
{
    std::vector<std::vector<int>> result;


    for (int i = 0; i < vector1.size(); ++i) {
        std::vector <int> temp;
        for (int j = 0; j < vector1.at(i).size(); ++j) {
            if ( vector1.at(i).at(j) > vector2.at(i).at(j))
               temp.push_back(vector1.at(i).at(j));
            else
                temp.push_back(vector2.at(i).at(j));
        }
        result.push_back(temp);
    }
    return result;
}


int main()
{

    std::vector<std::vector<int>> vector1 = { {2, 1}, {0, 1}};
    std::vector<std::vector<int>> vector2 = { {0, 1}, {-1, 1}};

    std::vector<std::vector<int>> newVector1 = biggerValue(vector1, vector2);

    std::cout << "[" << std::endl;
    for (int i = 0; i < newVector1.size(); i++){
        std::cout << "[";
        for (int j = 0; j < newVector1.at(i).size(); ++j) {
            std::cout << newVector1.at(i).at(j) << ",";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;

    std::vector<std::vector<int>> vector3 = { {-1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    std::vector<std::vector<int>> vector4 = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    std::vector<std::vector<int>> newVector2 = biggerValue(vector3, vector4);

    std::cout << "[" << std::endl;
    for (int i = 0; i < newVector2.size(); i++){
        std::cout << "[";
        for (int j = 0; j < newVector2.at(i).size(); ++j) {
            std::cout << newVector2.at(i).at(j) << ",";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;


    return 0;
}
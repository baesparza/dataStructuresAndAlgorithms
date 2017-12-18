#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& arr) {
    for (std::vector<int> a: arr) {
        std::cout << "{";
        for (int j = 0; j < a.size(); j++) std::cout << a[j] << ",";
        std::cout << "}" << std::endl;
    }
}

std::vector<std::vector<int>>& rotateImage(std::vector<std::vector<int>> a) {

     std::vector<std::vector<int>> temp = a;

     // we iterate trough the array pushing back all items in first, second, ... place
     for (int i = 0; i < temp.size(); i++) {
          for (int j = 0; j < temp[i].size(); j++) {
               a[i][j] = temp[j][i];
          }
     }

     return a;
}

int main() {

    std::vector<std::vector<int>> matriz {
                    std::vector<int> {1,2,3},
                    std::vector<int> {4,5,6},
                    std::vector<int> {7,8,9}
                };

    std::cout << "Matrix: " << std::endl;
    print(matriz);
    std::cout << "Rotated: " << std::endl;
    print(rotateImage(matriz));

    return 0;
}

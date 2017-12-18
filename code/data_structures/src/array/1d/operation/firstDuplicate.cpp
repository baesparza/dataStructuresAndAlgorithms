#include <iostream>
#include <vector>
#include <unordered_map>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

int firstDupicate(std::vector<int> a) {

    // we create an unordered_map, to check for items with a key "values"; and increase it.
    std::unordered_map<int, int> visited ;

    // we iterate through the array from 0
    for (int i=0; i < a.size(); i++) {

        visited[a[i]]++;
        // if the value is >= 2 is because it is repeated
        if (visited[a[i]] >= 2) {
            return a[i];
        }
    }

    return -1;
}

int main() {

    std::vector<int> vecA {1776,7,4};
    print(vecA);
    std::cout << "Result: " << firstDupicate(vecA) << std::endl;

    return 0;
}

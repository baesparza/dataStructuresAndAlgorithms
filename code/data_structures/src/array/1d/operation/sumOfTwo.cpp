#include <iostream>
#include <vector>
#include <unordered_map>

bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v) {

    /*
     * You have two integer arrays, a and b, and an integer target value v.
     * Determine whether there is a pair of numbers, where one number is taken from a and the other from b,
     * that can be added together to get a sum of v.
     * Return true if such a pair exists, otherwise return false.
     */

    std::unordered_map<int, int> visited;

    std::vector<int> bigger;
    std::vector<int> smaller;

    // to reduce unnecessary time, we check the smaller array
    if (a.size() > b.size()) {
        bigger = a;
        smaller = b;
    } else {
        bigger = b;
        smaller = a;
    }

    // we add the difference between the sum and the numb in the array
    for (int i = 0; i < smaller.size(); i++) { //&& smaller[i] <= v
        visited[v - smaller[i]] = 1;
    }
    // we check if an item exist
    // if it exists the program ends
    for (int i = 0; i < bigger.size(); i++) { //&& bigger[i] <= v
        if (visited[bigger[i]] == 1) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<int> arr1 {10, 1, 5, 3, 8};
    std::vector<int> arr2 {100, 6, 3, 1, 5};
    int sum = 4;
    std::cout << "Result: " << sumOfTwo(arr1, arr2, sum) << std::endl;
    return 0;
}

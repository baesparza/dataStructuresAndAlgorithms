#include <iostream>
#include <vector>
#include <algorithm>

bool containsDuplicates(std::vector<int> a) {
    std::sort(a.begin(), a.end());

    // we iterate through the array from 1
    for (int i=1; i < a.size(); i++) {

        // if value is repeated, the next item will have the same value
        // and return true
        if (a[i] == a[i - 1]) {
            return true;
        }
    }

    return false;
}

int main() {

    std::vector<int> vecA, vecB;

    int a[] = {1776,7,4};
    int b[] = {3,4,4};

    vecA.assign(a, a+3);
    vecB.assign(b, b+3);

    std::cout << "VecA: " << containsDuplicates(vecA) << std::endl;
    std::cout << "VecB: " << containsDuplicates(vecB) << std::endl;

    return 0;
}

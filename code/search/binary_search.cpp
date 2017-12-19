#include <iostream>
#include <vector>

int binary_search(std::vector<int>& arr, int start, int stop, int num) {
    /*Binary search, return number if found, or -1 if not*/
    /*arr should be sorted*/
    int middle = (start + stop) / 2;

    // base case
    if (stop < start) return -1; // item not found
    if (arr[middle] == num) return num; // when item is found

    // check left side or left side
    if (num > arr[middle]) // search right side
        return binary_search(arr, middle +1, stop, num);
    return binary_search(arr, start, middle-1, num); // check left side
}

int main() {
    /*test*/
    std::vector<int> arr {0,1,2,3,4,5,6,7,8,9};
    std::cout << binary_search(arr, 0, arr.size()-1, -1) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 0) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 1) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 2) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 3) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 4) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 5) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 6) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 7) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 8) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 9) << std::endl;
    std::cout << binary_search(arr, 0, arr.size()-1, 10) << std::endl;
}

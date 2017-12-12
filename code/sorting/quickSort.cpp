#include <vector>
#include <iostream>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}



int main() {
    std::vector<int> arr = {5,3,2,4,1};
    print(arr);

    /*test*/
    std::cout << "Sorted array" << std::endl;
    // print(mergeSort(arr));
    return 0;
}



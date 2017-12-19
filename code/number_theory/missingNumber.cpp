#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

int missingNumber(std::vector<int> arr) {
    /*
     * You are supposed to label a bunch of boxes with numbers from 0 to n,
     * and all the labels are stored in the array arr
     */
    std::sort(arr.begin(), arr.end()); //sort element

    for (int i = 0; i < arr.size() - 1; i++) {
        if ((arr[i] + 1) != arr[i + 1]) {
            return arr[i] + 1;
        }
    }

    // special case
    if (arr[0] == 0) {
        return arr[arr.size() - 1] + 1;
    }

    return 0;
}

int main() {
    std::vector<int> arr = {5,3,2,4,1,7};
    print(arr);

    /*test*/
    std::cout << "Missing number: " << missingNumber(arr) << std::endl;
    return 0;
}

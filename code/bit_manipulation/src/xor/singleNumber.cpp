#include <iostream>
#include <vector>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

int singleNumber(std::vector<int> nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}


int main() {
    std::vector<int> arr = {5,3,2,3,2};
    print(arr);

    /*test*/
    std::cout << "singleNumber" << std::endl
    << singleNumber(arr);
    return 0;
}

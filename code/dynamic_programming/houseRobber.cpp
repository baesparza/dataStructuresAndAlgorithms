#include <iostream>
#include <vector>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

int houseRobber(std::vector<int> nums) {

   std::vector<int> index(nums.size());

    // base cases
    if (nums.size() == 0) {
        return 0;
    }
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }

    // we try to keep the highest value at the end of the array
    index[0] = nums[0];
    index[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        index[i] = std::max(index[i - 2] + nums[i], index[i - 1]);
        print(index);
    }

    return index[nums.size() - 1];
}

int main() {
    std::vector<int> arr = {1, 7, 9, 4};
    print(arr);

    /*test*/
    std::cout << "Max: " << houseRobber(arr) << std::endl;
}

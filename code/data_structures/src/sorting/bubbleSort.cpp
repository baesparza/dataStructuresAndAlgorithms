#include <vector>
#include <iostream>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

std::vector<int> &bubbleSort(std::vector<int> &arr) {
    int temp;
    for(int i = 0; i < arr.size(); i++) { // know number of sorted items
        for (int j = 0; j < arr.size() - i - 1; j++) { // limit to pass sorted item, and don`t check last item to can compare with
            if (arr[j] > arr[j + 1]) { // swap values
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    std::vector<int> arr = {5,3,2,4,1};
    print(arr);

    /*test*/
    std::cout << "Sorted array" << std::endl;
    print(bubbleSort(arr));
    return 0;
}

#include <iostream>
#include <vector>

void print(std::vector<int> arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

std::vector<int> mergeKArrays(std::vector<std::vector<int>> arrays) {
    /*Given K sorted arrays, return their sorted concatenation.*/
    /*n arrays are passed as one vector of arrays*/

    // we create 2 arrays
    // the first one is to store the arrays size
    // the the second for the final result
    std::vector<int> firstUnused(arrays.size(), 0), result;

    // get the total size
    int n = 0;
    for (std::vector<int> arr: arrays) n += arr.size();

    // we iterate trough all items in all arrays
    for (int i = 0; i < n; i++) {
        int minIndex = -1,
            minValue = 0;
        // we iterate trough the arrays
        for (int j = 0; j < arrays.size(); j++) {
            // we check if the array has items non used
            if (firstUnused[j] < arrays[j].size()) {
                // we check the values that we already used stored in firstUnused
                // we check in every loop for the min value in every array, and select the min val to be pushed
                if ( minIndex == -1 || minValue > arrays[j][firstUnused[j]] ) {
                    // we store the values in global variables
                    minIndex = j; //
                    minValue = arrays[j][firstUnused[j]];
                }
            }
        }
        // we push the final results
        result.push_back(minValue);
        firstUnused[minIndex]++;
    }
  return result;
}

int main() {
    std::vector<std::vector<int>> arrays = {
                        std::vector<int> {1,2,3},
                        std::vector<int> {3,5,9},
                        std::vector<int> {2,6,8}
                };
    for (std::vector<int> arr: arrays) print(arr);


    /*test*/
    std::cout << "merge K Arrays" << std::endl;
    print(mergeKArrays(arrays));
    return 0;
}

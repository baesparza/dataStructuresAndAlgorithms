#include <vector>
#include <iostream>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

void mergeArrays(std::vector<int> &sequence, int left, int middle, int right) {
    std::vector<int> result; // were merged arr's will be stored
    int i, j; // keep track of pushed items of each arr

    for (i = left, j = middle; i < middle && j < right; ) { // push minor values first
        if (sequence[i] < sequence[j]) {
            result.push_back(sequence[i]);
            i++;
        }
        else {
            result.push_back(sequence[j]);
            j++;
        }
    }

    // push items that has not been pushed already
    while (i < middle) {
        result.push_back(sequence[i]);
        i++;
    }
    while (j < right) {
        result.push_back(sequence[j]);
        j++;
    }

    // push sorted items to main arr reference
    for (i = left; i < right; i++) {
        sequence[i] = result[i - left];
    }
}

void split(std::vector<int> &sequence, int left, int right) {
    /*split array until each arr size is 1 or less*/
    if (right - left <= 1) return; // return and continue algorithm can't split min size arr
    int middle = (left + right) / 2;
    // split left side of arr and right side too
    split(sequence, left, middle);
    split(sequence, middle, right);
    mergeArrays(sequence, left, middle, right); // merge arrays in sorted way
}

std::vector<int>& mergeSort(std::vector<int> &sequence) {

    split(sequence, 0, sequence.size());
    // first step of merge sort is to split arr
    return sequence;
}

int main() {
    std::vector<int> arr = {5,3,2,4,1};
    print(arr);

    /*test*/
    std::cout << "Sorted array" << std::endl;
    print(mergeSort(arr));
    return 0;
}


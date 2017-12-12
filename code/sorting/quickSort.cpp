#include <vector>
#include <iostream>

void print(std::vector<int> &arr) {
    std::cout << "Array: {";
    for (int j = 0; j < arr.size(); j++) std::cout << arr[j] << ",";
    std::cout << "}" << std::endl;
}

void quickSortWithReference(std::vector<int> &a, int l, int r) {
    if (l >= r) return; // if we can`t sort at least 2 items and break the infinite loop

    // we set the first item as a starting point were it can "split" the array.
    int x = a[l];
    int i = l;
    int j = r;

    while (i <= j) {
        // int this loop we move the values to be with it equals, (higher w/ higher) (slower w/ slower)
        // check if there is a higher value to be swapped
        while (a[i] < x) i++;
        while (a[j] > x) j--;

        if (i <= j) {
            // we swap values and keep going with the algorithm
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }

    // we call the function to sort the smaller groups, until it break and the algorithm ends
    // this will activate when i > j and thats why we send (.., l, j), (.., i, r)
    quickSortWithReference(a, l, j);
    quickSortWithReference(a, i, r);
}

std::vector<int> &quickSort(std::vector<int> &arr, int l, int r) {
    quickSortWithReference(arr, l, r);
    return arr;
}


int main() {
    std::vector<int> arr = {5,3,2,4,1};
    print(arr);

    /*test*/
    std::cout << "Sorted array" << std::endl;
    print(quickSort(arr, 0, arr.size()));
    return 0;
}



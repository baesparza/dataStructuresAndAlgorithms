#include <iostream>

void xor_swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    /*
     * This operation is performed between two bits (a and b).
     * The result is 1 if either one of the two bits is 1, but not in the case that both are.
     * There for, if neither or both of them are equal to 1 the result is 0.
     */
    int a = 10, b = 15;

    std::cout << "Before swapping: A = " << a << " and B = " << b << std::endl;

    xor_swap(&a, &b);

    std::cout << "After swapping: A = " << a << " and B = " << b << std::endl;

    return 0;
}

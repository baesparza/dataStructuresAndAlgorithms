#include <iostream>

int factorial(int num) {
    if (num == 0) return 1;
    return num * factorial(num - 1);
}

int main() {
    std::cout << "Factorial of " << 6 << ": " << factorial(6) << std::endl;
    std::cout << "Factorial of " << 5 << ": " << factorial(5) << std::endl;
    std::cout << "Factorial of " << 4 << ": " << factorial(4) << std::endl;
    std::cout << "Factorial of " << 3 << ": " << factorial(3) << std::endl;
    std::cout << "Factorial of " << 2 << ": " << factorial(2) << std::endl;
    std::cout << "Factorial of " << 1 << ": " << factorial(1) << std::endl;
}

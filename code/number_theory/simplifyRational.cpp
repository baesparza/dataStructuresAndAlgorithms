#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> simplifyRational(int numerator, int denominator) {

    // check if one of the values are 0 to return 0
    if (numerator == 0) {
        return std::vector<int> {0, 1};
    }

    // since we can`t return a negative denominator we transform to positive
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    for (int i = 2; i <= std::min(std::abs(numerator), denominator); i++) {
    	while ((numerator % i == 0) && (denominator % i == 0)) {
    		numerator /= i;
    		denominator /= i;
    	}
    }

    return std::vector<int> {numerator, denominator};
}

int main() {
    std::vector<int> arr = simplifyRational(-18, -24);
    std::cout << arr[0] << "/" << arr[1] << std::endl;
    return 0;
}

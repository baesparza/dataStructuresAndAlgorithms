#include <iostream>

int lazyCutter(int n) {
    int result = 1;
    for (int i = 0; i <= n; i++) result+= i;
    return result;
}

int main() {
    std::cout << "n = 10: " << lazyCutter(10) << std::endl;
    return 0;
}

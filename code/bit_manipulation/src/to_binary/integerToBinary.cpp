/*#include <iostream>
#include <string>
#include <algorithm>

std::string integerToBinary(int value) {
    std::string res = "";
    while (value >= 0) {
        res = std::to_string(value % 2) + res;
        value = value / 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main () {
    std::cout << "10: " << integerToBinary(10) << std::endl;
    return 0;
}
*/
#include <iostream>
#include <string>

int main()
{
    double f = 23.43;
    std::string f_str = std::to_string(f);
    std::cout << f_str << '\n';
}

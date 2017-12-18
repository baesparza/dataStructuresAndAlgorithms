#include <iostream>
#include <unordered_map>

char firstNotRepeatingCharacter(std::string s) {
    /*
     * Given a string s, find and return the first instance of a non-repeating character in it.
     * If there is no such character, return '_'.
     */
    std::unordered_map<char, char> visitedChar ;

    // create a map with all chars
    for (char & c : s) {
        visitedChar[c] ++;
    }

    // check non repeating character
    for (char & c : s) {
        if (visitedChar[c] == 1) {
            return c;
        }
    }

    return '_';
}



int main() {
    std::string test = "ngrhhqbhnsipkcoqjyviikvxbxyphsnjpdxkhtadltsuxbfbrkof";
    std::cout << "test3: " << test << std::endl;
    std::cout << "result: " << firstNotRepeatingCharacter(test) << std::endl;
    return 0;
}

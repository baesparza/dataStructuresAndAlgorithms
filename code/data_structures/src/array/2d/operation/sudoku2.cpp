#include <iostream>
#include <vector>
#include <unordered_map>

void print(std::vector<std::vector<char>>& arr) {
    for (std::vector<char> a: arr) {
        std::cout << "{";
        for (char j : a) std::cout << j << ",";
        std::cout << "}" << std::endl;
    }
}

bool sudoku2(std::vector<std::vector<char>> grid) {

    int gridSize = grid.size();

    // check unique
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if(grid[i][j] == '.') continue; // check if item
            char mainNum = grid[i][j];
            // check horizontally
            for (int j_temp = j + 1; j_temp < gridSize; j_temp++) {
                if (grid[i][j_temp] == mainNum) return false;
            }

            // check vertically
            for (int i_temp = i + 1; i_temp < gridSize; i_temp++) {
                if (grid[i_temp][j] == mainNum) return false;
            }
        }
    }

    // 3 x 3 check
    // loop to iterate thought all the array
    for (int i = 0; i < gridSize; i += 3) {
        for (int j = 0; j < gridSize; j += 3) {
            // loop to iterate though the items in each 3 x 3
            std::unordered_map<int, int> tempRepeated;
            for (int i_temp = i; i_temp < i + 3; i_temp++ ) {
                for (int j_temp = j; j_temp < j + 3; j_temp++ ) {
                    if (grid[i_temp][j_temp] == '.') continue; // check if item
                    tempRepeated[grid[i_temp][j_temp]]++;

                    // if the value is >= 2 is because it is repeated
                    if (tempRepeated[grid[i_temp][j_temp]] >= 2) return false;
                }
            }
        }
    }

    return true;
}

int main() {

    std::vector<std::vector<char>> matrix {
            {'.', '.', '.', '1', '4', '.', '.', '2', '.'},
            {'.', '.', '6', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'.', '.', '1', '.', '.', '.', '.', '.', '.'},
            {'.', '6', '7', '.', '.', '.', '.', '.', '9'},
            {'.', '.', '.', '.', '.', '.', '8', '1', '.'},
            {'.', '3', '.', '.', '.', '.', '.', '.', '6'},
            {'.', '.', '.', '.', '.', '7', '.', '.', '.'},
            {'.', '.', '.', '5', '.', '.', '.', '7', '.'}
        };

    std::cout << "Grid: " << std::endl;
    print(matrix);
    std::cout << "Sudoku: " << sudoku2(matrix) << std::endl;
    return 0;
}

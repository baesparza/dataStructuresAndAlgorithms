#include <iostream>
#include <vector>

std::vector<bool> squaresUnderQueenAttack(int n, std::vector<std::vector<int>> queens, std::vector<std::vector<int>> queries) {
    std::vector<bool> result (queries.size(), false);

    for (int iQuery = 0; iQuery < queries.size(); iQuery++) {
        for (int i = 0; i < queens.size(); i++) {
            if (queries[iQuery][0] == queens[i][0] || queries[iQuery][1] == queens[i][1] ||
                queries[iQuery][0] - queries[iQuery][1] == queens[i][0] - queens[i][1] ||
                queries[iQuery][0] + queries[iQuery][1] == queens[i][0] + queens[i][1]) {
                result[iQuery] = true;
            }
        }
    }
    return result;
}

int main() {

    std::vector<std::vector<int>> queens {{1,0}, {1,1}};

    std::vector<std::vector<int>> queries {{0,0}, {0,1}, {0,2},
            {0,3}, {1,0}, {1,1}, {1,2}, {1,3}, {2,0}, {2,1},
            {2,2}, {2,3}, {3,0}, {3,1}, {3,2}, {3,3}};

    std::vector<bool> result = squaresUnderQueenAttack(4, queens, queries);
    return 0;
}

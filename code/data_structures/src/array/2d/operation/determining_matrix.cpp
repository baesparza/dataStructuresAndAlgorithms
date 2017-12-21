#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& arr) {
	for (std::vector<int> a : arr) {
		std::cout << "{";
		for (int b : a) std::cout << b << ",";
		std::cout << "}" << std::endl;
	}
}

int calc(std::vector<std::vector<int>>& matrix, int start, int iterator) {
	int result = 0; // final result
	for (int i = 0; i < matrix.size(); i++) {
		int temp = 1; // store multiplication
		for (int loop = 0, j = i, l = start; loop < matrix.size(); loop++, j++, l += iterator) {
			if (j == matrix.size()) j = 0; // restart beginning
			temp *= matrix[j][l];
		}
		result += temp;
	}
	return result * iterator;
}

int determining_matrix(std::vector<std::vector<int>>& matrix) {
	return calc(matrix, 0, 1) + calc(matrix, matrix.size() - 1, -1);
}

int main() {

	std::vector<std::vector<int>> matrix{
		std::vector<int> {2,1,3},
		std::vector<int> {4,-1,2},
		std::vector<int> {-3,4,2}
	};

	std::cout << "Matrix: " << std::endl;
	print(matrix);
	std::cout << "Determining Matrix: " <<  determining_matrix(matrix) << std::endl;
	std::cin.get();
	return 0;
}
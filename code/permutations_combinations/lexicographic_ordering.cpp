#include <iostream>
#include <array>

int main()
{
	// gen main array
	std::array<int, 5> nums;
	for (int i = 0; i < nums.size(); i++)
		nums[i] = i;

	while (true)
	{
		// print array
		for (int n : nums)
			std::cout << n << ", ";
		std::cout << "\n";

		// 1. Find the largest x such that P[x]<P[x+1].
		// (If there is no such x, P is the last permutation.)
		int smalestX = -1;
		for (int i = 0; i < nums.size() - 1; i++)
			if (nums[i] < nums[i + 1])
				smalestX = i;
		if (smalestX == -1)
			break;

		int smalestY = -1;
		// 2.Find the largest y such that P[x]<P[y].
		for (int i = 0; i < nums.size(); i++)
			if (nums[smalestX] < nums[i])
				smalestY = i;

		// 3.Swap P[x] and P[y].
		int temp = nums[smalestX];
		nums[smalestX] = nums[smalestY];
		nums[smalestY] = temp;

		// 4.Reverse P[x + 1 ..n].
		std::reverse(std::begin(nums) + smalestX + 1, std::end(nums));
	}

	std::cin.get();
	return 0;
}
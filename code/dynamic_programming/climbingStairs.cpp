#include <iostream>

int climbingStairs(int n) {
    /* You are climbing a staircase that has n steps.
     * You can take the steps either 1 or 2 at a time.
     * Calculate how many distinct ways you can climb to the top of the staircase
     */
    // similar to the Fibonacci sec

    // we create an array with reference
    // the size is n + 1, to let the last item be the result
    int* A = new int[n+1];

    // the first 2 items as the fib sec to 1
    A[0] = A[1] = 1;


    for(int i = 2 ; i <= n ; i++) {
        {A[i] = A[i-1] + A[i-2];}
    }

    return A[n];
}

int main()
{
    std::cout << "Input: " << 42 << std::endl;
    std::cout << "Result: " << climbingStairs(42) << std::endl;
    return 0;
}

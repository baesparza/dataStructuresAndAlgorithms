#include <iostream>

int fib(int n) {
    /*Calculate Fibonacci of n*/
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
    std::cout << "Input: " << 5 << std::endl;
    std::cout << "Result: " << fib(5) << std::endl;
    return 0;
}

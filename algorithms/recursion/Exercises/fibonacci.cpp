/*Fibonacci Sequence*/

#include <iostream>

// Traditional recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Memoized recursive function to calculate Fibonacci numbers
int fibonacciMemo(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }
    if (memo[n-2] == -1) {
        memo[n-2] = fibonacciMemo(n - 2, memo);
    }
    if (memo[n-1] == -1) {
        memo[n-1] = fibonacciMemo(n - 1, memo);
    }
    return memo[n-1] + memo[n-2];   
}


int main() {
    int n = 10; // Calculate Fibonacci numbers up to n
    int memo[n];
    
    // Initialize memoization array with -1
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }

    std::cout << "Fibonacci sequence using traditional recursion: ";
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Fibonacci sequence using memoization: ";
    for (int i = 0; i < n; i++) {
        std::cout << fibonacciMemo(i, memo) << " ";
    }
    std::cout << std::endl;

    return 0;
}
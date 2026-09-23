/* Calculate nCr (n choose r) using recursion */

#include <iostream>

int nCr(int n, int r) {
    // Base cases
    if (r == 0 || r == n) {
        return 1;
    }
    // Recursive case
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
    int n = 5; // Total number of items
    int r = 2; // Number of items to choose

    std::cout << "nCr (" << n << " choose " << r << ") = " << nCr(n, r) << std::endl;

    return 0;
}
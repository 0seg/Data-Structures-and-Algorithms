#include <iostream>

int pow(int m, int n) {
    // This function calculates m raised to the power of n using recursion.
    if (n == 0) {
        return 1;
    }
    if(n % 2 == 0) {
        return pow(m * m, n / 2);
    }
    return m * pow(m * m, (n - 1)/2);
}

int main(){

    int m = 2;
    int n = 10;
    std::cout << m << " raised to the power of " << n << " is: " << pow(m, n) << std::endl;

    return 0;


}
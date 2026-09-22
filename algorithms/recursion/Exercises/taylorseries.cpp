/*taylor series e^x = 1 + x/1! + x^2/2! + x^3/3! + ... */

#include <iostream>

double taylorSeries(int x, int n){
    static double p = 1, f = 1;
    double r;

    if(n == 0){
        return 1;
    } else {
        r = taylorSeries(x, n - 1);
        p *= x;
        f *= n;
        return r + p / f;
    }

}

int main() {
    int x = 1; // Value of x
    int n = 10; // Number of terms in the series

    std::cout << "e^" << x << " using Taylor series approximation: " << taylorSeries(x, n) << std::endl;

    return 0;
}
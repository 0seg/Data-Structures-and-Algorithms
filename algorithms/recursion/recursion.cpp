#include <iostream>

int func1(int n){
    if (n > 0){
        std::cout << n << " ";
        return func1(n - 1);
    }
    return 0;
}

int func2(int n){
    if (n > 0){
        func2(n - 1); 
        std::cout << n << " ";
    }
    return 0;
}

int factorial(int n) {
    if (n <= 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}


int main(){

    int n = 5;

    std::cout << "Calling func1 with n = " << n << ": ";
    func1(n); // This will print numbers from n down to 1
    std::cout << std::endl;

    std::cout << "Calling func2 with n = " << n << ": ";
    func2(n); // Prints numbers from 1 to n    
    std::cout << std::endl;

    int fact = factorial(n);
    std::cout << "Factorial of " << n << " is: " << fact << std::endl;

    return 0;


    
}
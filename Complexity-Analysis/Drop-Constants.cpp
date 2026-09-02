#include <iostream>
using namespace std;

void printNumbers(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << endl;
}
// The time complexity of the `printNumbers` function is O(n), where n is the input parameter.

void printNumbers2(int n) {
    for (int j = 1; j <= n; ++j) {
        cout << j << " ";
    }
    cout << endl;
}
// The time complexity of the `printNumbers2` function is also O(n), where n is the input parameter.




int main(){

    printNumbers(10); // Example usage with n = 10
    printNumbers2(10); // Example usage with n = 10
    
    // When we call both functions in the main function, the overall time complexity is O(n) + O(n) = O(2n). 
    // However, in Big O notation, we drop constant factors, so O(2n) simplifies to O(n).
    // Therefore, the overall time complexity of the main function is O(n).

    return 0;

}

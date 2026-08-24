#include <iostream>
using namespace std;

void printNumbers(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    printNumbers(10); // Example usage with n = 10
    return 0;
}

// The time complexity of the `printNumbers` function is O(n), where n is the input parameter. 
// This is because the function contains a single loop that iterates from 1 to n, performing a constant-time operation (printing) during each iteration. 
// Therefore, the overall time taken grows linearly with the size of n.

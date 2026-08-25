#include <iostream>
using namespace std;

int addItems(int n){
    return n + n; 
    // The time complexity of the `addItems` function is O(1), which means it runs in constant time regardless of the input size n.

}


int main(){

    int result = addItems(10); // Example usage with n = 10
    cout << "Result: " << result << endl;

    // The time complexity of the main function is O(1) because it calls the `addItems` function, which has a time complexity of O(1).

    return 0;


}
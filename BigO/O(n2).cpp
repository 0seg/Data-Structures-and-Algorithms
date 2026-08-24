#include <iostream>
using namespace std;

void printNumbers(int n){

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << i << " " << j << endl;
        }
    }

} // The time complexity of the `printNumbers` function is O(n^2), where n is the input parameter.



int main(){

    printNumbers(10); // Example usage with n = 10
    
    // The time complexity of the main function is O(n^2) because it calls the `printNumbers` function, which has a time complexity of O(n^2).


    return 0;



}

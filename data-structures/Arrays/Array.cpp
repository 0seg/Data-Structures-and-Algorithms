/* Array Implementation */

#include <iostream>

int main() {
    // Create an array of integers
    int arr[5] = {1, 2, 3, 4, 5};

    // Print the elements of the array
    std::cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Modify an element in the array
    arr[2] = 10;
    std::cout << "Modified array elements: ";
    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
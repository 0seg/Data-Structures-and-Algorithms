#include <iostream>
#include <stdexcept>


template <typename T>

class Array{
    
  
    private:
        T* data;
        unsigned int size;
        unsigned int capacity;

        void resize(){
                capacity *= 2;

                T* datatemp = data; 

                T* dataNew = new T[capacity];

                for(size_t i{}; i < size; ++i){
                    dataNew[i] = datatemp[i];
                }

                delete[] datatemp;

                data = dataNew;
        }
    
    public:

        //Constructor
        Array(unsigned int size, unsigned int capacity) : size{size}, capacity{capacity}{
            data = new T[capacity];
        } 

        //Destructor
        ~Array(){
            delete[] data;
        }

        // Get
        T getPosition(unsigned int i){
            if(i < size){
                return data[i];
            }
            throw std::out_of_range("Index out of range");
        }
        
        // Set
        void modifyPosition(unsigned int i, T value){
            if(i < size){
                data[i] = value;
                return;
            }
            throw std::out_of_range("Index out of range");
        }


        void append(T value){
            if (size == capacity){
                resize();
            }
            data[size] = value;
            ++size;
        }

        void insert(int i, T value){
            if(i < 0 || i > static_cast<int>(size)){
                throw std::out_of_range("Index out of range");
            }
            if (size == capacity){
                resize();
            }

            for(int e{static_cast<int>(size) - 1}; e >= i; --e){
                data[e+1] = data[e];
            }
            data[i] = value;
            ++size;

        }

        void remove(unsigned int i){
            if(i >= size){
                throw std::out_of_range("Index out of range");
            }
            for (int e = i; e < static_cast<int>(size) - 1; ++e) {
                data[e] = data[e + 1];
            }
            --size;
        }

        unsigned int linear_search(T value){
            for(size_t i{}; i<size; i++){
                if(data[i] == value){
                    return i;
                }
            }
            return size;
        }

        int binary_search(T value){
            int l{};
            int r {static_cast<int>(size) - 1};

            while(l<=r){
                int mid{(l + r)/2}; 
                
                if(value == data[mid]){
                    return mid;
                }

                else if (data[mid] < value){
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return -1;
        }


};


int main() {

    // 1. Create Array
    Array<int> arr{0, 3};

    std::cout << "=== APPEND ===\n";

    arr.append(10);
    arr.append(20);
    arr.append(30); // Call resize() here

    std::cout << arr.getPosition(0) << '\n';
    std::cout << arr.getPosition(1) << '\n';
    std::cout << arr.getPosition(2) << '\n';


    // 2. Modify
    std::cout << "\n=== MODIFY ===\n";

    arr.modifyPosition(1, 99);

    std::cout << arr.getPosition(1) << '\n';


    // 3. Insert
    std::cout << "\n=== INSERT ===\n";

    arr.insert(0, 5);   // Start
    arr.insert(2, 15);  // Middle
    arr.insert(5, 40);  // End

    for (unsigned int i{}; i < 6; ++i) {
        std::cout << arr.getPosition(i) << ' ';
    }

    std::cout << '\n';


    // 4. Linear search
    std::cout << "\n=== LINEAR SEARCH ===\n";

    std::cout << "15 -> " << arr.linear_search(15) << '\n';
    std::cout << "999 -> " << arr.linear_search(999) << '\n';


    // 5. Binary search
    std::cout << "\n=== BINARY SEARCH ===\n";

    // IMPORTANT: binary_search requires the array to be sorted.
    Array<int> sorted{0, 5};

    sorted.append(10);
    sorted.append(20);
    sorted.append(30);
    sorted.append(40);
    sorted.append(50);

    std::cout << "30 -> " << sorted.binary_search(30) << '\n';
    std::cout << "50 -> " << sorted.binary_search(50) << '\n';
    std::cout << "99 -> " << sorted.binary_search(99) << '\n';


    // 6. Remove
    std::cout << "\n=== REMOVE ===\n";

    sorted.remove(2);

    for (unsigned int i{}; i < 4; ++i) {
        std::cout << sorted.getPosition(i) << ' ';
    }

    std::cout << '\n';


    // 7. Exceptions
    std::cout << "\n=== EXCEPTIONS ===\n";

    try {
        sorted.getPosition(100);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    try {
        sorted.remove(100);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << '\n';
    }

    return 0;
}
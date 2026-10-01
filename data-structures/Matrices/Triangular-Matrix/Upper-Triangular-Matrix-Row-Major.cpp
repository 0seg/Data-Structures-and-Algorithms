/* Upper Triangular Matrix - Row Major Order */

#include <iostream>

class UpperTriangularMatrix{
    private:
        int n;
        int* data;

    public:
        UpperTriangularMatrix(int n) : n{n} {
            data = new int[n*(n+1)/2];
        
        }
        ~UpperTriangularMatrix() {
            delete[] data;
        }
        
        void set(unsigned int i, unsigned int j, int x){
            if(i <= j){
                data[i*n - (i*(i-1))/2 + (j-i)] = x;
            }
        }

        int get(unsigned int i, unsigned int j){
            if(i <= j){
                return data[i*n - (i*(i-1))/2 + (j-i)];
            }else{
                return 0;
            }
        }

        void display(){
            for(size_t i{0}; i < n; ++i){
                for(size_t j{0}; j < n; ++j){
                    if(i <= j){
                        std::cout << data[i*n - (i*(i-1))/2 + (j-i)] << ' ';
                    }else{
                        std::cout << '0' << ' ';
                    }
                }
                std::cout << "\n";
            }
        }

};
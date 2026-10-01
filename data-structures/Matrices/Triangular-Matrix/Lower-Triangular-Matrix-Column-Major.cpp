/* Lower Triangular Matrix - Column Major Order */

#include <iostream>

class LowerTriangularMatrix{
    private:
        int n;
        int* data;

    public:
        LowerTriangularMatrix(int n) : n{n} {
            data = new int[n*(n+1)/2];
        
        }
        ~LowerTriangularMatrix() {
            delete[] data;
        }
        
        void set(unsigned int i, unsigned int j, int x){
            if(i >= j){
                data[j*(2*n-j+1)/2 + (i-j)] = x;
            }
        }

        int get(unsigned int i, unsigned int j){
            if(i >= j){
                return data[j*(2*n-j+1)/2 + (i-j)];
            }else{
                return 0;
            }
        }

        void display(){
            for(size_t i{0}; i < n; ++i){
                for(size_t j{0}; j < n; ++j){
                    if(i >= j){
                        std::cout << data[j*(2*n-j+1)/2 + (i-j)] << ' ';
                    }else{
                        std::cout << '0' << ' ';
                    }
                }
                std::cout << "\n";
            }
        }

};
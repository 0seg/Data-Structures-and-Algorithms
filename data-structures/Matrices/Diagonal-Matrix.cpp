#include <iostream>

class DiagonalMatrix{
    private:
        int n;
        int* data;

    public:
        DiagonalMatrix(int n) : n{n} {
            data = new int[n];
        
        }
        ~DiagonalMatrix() {
            delete[] data;
        }
        
        void set(unsigned int i, unsigned int j, int x){
            if(i == j){
                data[i] = x;
            }
        }

        int get(unsigned int i, unsigned int j){
            if(i == j){
                return data[i];
            }
        }

        void display(){
            for(size_t i{0}; i < n; ++i){
                for(size_t j{0}; j < n; ++j){
                    if(i==j){
                        std::cout << data[i] << ' ';
                    }else{
                        std::cout << '0' << ' ';
                    }
                }
                std::cout << "\n";
            }
        }

    };

int main(){

    DiagonalMatrix dm(4);
    dm.set(0, 0, 1);
    dm.set(1, 1, 2);
    dm.set(2, 2, 3);
    dm.set(3, 3, 4);
    dm.display();


}
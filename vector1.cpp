// Demuestra la relación entre las direccciones y elementos de arreglos de diferentes tipos de datos

#include <iostream>
#include <vector>

using namespace std;

int A[10];
int x;
float B[10];
double C[10];

int main(){
    int vec[3] = {1, 2, 3};
    vector<int> v1 = {2, 3, 4};
    std::cout << vec << std::endl;
    std::cout << &vec << std::endl;
    std::cout << &vec[0] << std::endl;

    std::cout << v1.back()  << std::endl;
    std::cout << v1.front()  << std::endl;


    for(int x = 0; x<10; x++){
        std::cout << x << '\t'<<&A[x] <<'\t'<< &B[x] <<'\t'<< &C[x] << std::endl;
    }


    return 0;
}
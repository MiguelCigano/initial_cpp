#include <iostream>
using namespace std;

int vaciar_vec(unsigned char *vecA, unsigned char *vecB, unsigned char siz);

int main(){
    unsigned char siz = 7;
    unsigned char vecA[siz] = {20, 1, 1, 1, 1, 1, 10};
    char vec_abc[3] = {'a', 'b', 'c'};
    unsigned char vecB[siz] = {0, 10, 10, 10, 10, 10, 0};
    
    for (unsigned char j = 0; j<siz; j++){
        cout << vecA[j] << " ";
    }
    cout << endl;
    for (unsigned char j = 0; j<siz; j++){
        cout << vecB[j] << " ";
    }
    cout << endl;    
    vaciar_vec(vecA, vecB, siz);
    std::cout << sizeof(vecA) << std::endl;
    std::cout << &vecA << std::endl;
    
    for(int i = 0; i < siz; i++) {
        cout << static_cast<int>(vecA[i]) << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << vec_abc[i] << " ";
    }
    cout << endl;              
    return 0;
}

int vaciar_vec(unsigned char *vecA, unsigned char *vecB, unsigned char siz){
    int vecB_[siz] = {0};
    // int *ptrB = vecB_;
    for (int j = 0; j<siz; j++ ){
        vecB[j] = vecA[j];
    }
    for (int j = 0; j<siz; j++){
        vecB_[j] = vecB[j];
    }
    cout << "Vector vaciado B: " << endl;
    for (int j = 0; j < siz; j++){
        cout << vecB_[j] << " ";
    }
    cout << endl;
    return *vecB_;
}
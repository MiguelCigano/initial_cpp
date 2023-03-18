// building vectors

#include <iostream>
#include <vector> //esta libreria no es necesaria para este codigo, indpendientemente de que usamos el operador "[]"

using namespace std;

int promedio_vec(unsigned char* myvec, unsigned char col);

int main(){
    unsigned char col = 7; // size
    unsigned char myvec[col] = {20, 1, 1, 1, 1, 1, 10};
    float mysum = 0;
    for (int j = 0; j<col; j++){
        mysum += myvec[j];
    }
    cout << mysum << endl;
    promedio_vec(myvec, col);
}

int promedio_vec(unsigned char* myvec, unsigned char col){
    float promedio = 0;
    float mysum = 0;
    int nvec[col] = {0};
    for (int j = 0; j<col; j++){
        mysum += myvec[j];
    }
    for (int j = 0; j<col; j++){
        nvec[j] = myvec[j];
    }
    cout << nvec << endl;
    cout << &myvec[2] << endl;
    promedio = mysum / col;
    cout << "suma: " << mysum << endl;
    cout << "promedio: " << promedio << endl;
    return 0;
}


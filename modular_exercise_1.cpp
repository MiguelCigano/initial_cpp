// building vectors

#include <iostream>
#include <vector>

using namespace std;

int promedio_vec(unsigned char *myvec, unsigned char col);

int main(){
    unsigned char col = 7; // size
    unsigned char myvec[col] = {10, 1, 1, 1, 1, 1, 10};
    float mysum = 0;
    for (int j = 0; j < col; j++){
        mysum += myvec[j];
    }
    cout << mysum << endl;
    promedio_vec(myvec, col);
}

int promedio_vec(unsigned char *myvec, unsigned char col){
    float promedio = 0;
    float mysum = 0;
    for (int j = 0; j < col; j++){
        mysum += myvec[j];
    }
    promedio = mysum / col;
    cout << "suma: " << mysum << endl;
    cout << "promedio: " << promedio << endl;
    return 0;
}


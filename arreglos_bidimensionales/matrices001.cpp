#include <iostream>
using namespace std;

int main(){
    int fila = 3, columna = 3;    
    int matriz[fila][columna];
    for (int i=0; i<fila; i++){
        for (int j = 0; j < columna; j++){
            cout << "num" << i+1 << j+1 << ":";
            cin >> matriz[i][j];
        }
    }
    
    for (int i = 0; i<fila; i++){
        for (int j=0; j<columna; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
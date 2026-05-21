#include <iostream>

using namespace std;
#define n 6

int main(){
    int numbers[n];
    for (int i = 0; i < n; i ++){
        cout << "ingrese num: \n";
        cin >> numbers[i];
    }
    cout << "Los numeros ingresados son: \n";
    for (int i = 0; i < n; i ++){
        cout << numbers[i];
    }
}

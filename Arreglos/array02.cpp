#include <iostream>

using namespace std;

void imprimir_valores(int *array, const int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int suma_valores(int *array, const int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s = s + array[i];
    }
    return s;
}

void abs_valores_array(int *array, const int n) {
    for (int i = 0; i < n; i++) {
        cout << abs(array[i]) << " ";
    }
    cout << endl;
}

int main() {
    const int n = 5;
    int s;
    int array_numeros[n];
    int array_numeros_abs[4] = {1, -2, -3, 4};

    // Lectura de valores por teclado
    for (int i = 0; i < n; i++) {
        cout << "Ingresa el valor #" << i + 1 <<": ";
        cin >> array_numeros[i];
    }

    imprimir_valores(array_numeros, n);
    s = suma_valores(array_numeros, n);
    abs_valores_array(array_numeros_abs, 4);

    cout << "Result is: " << s << endl;

    return 0;
}
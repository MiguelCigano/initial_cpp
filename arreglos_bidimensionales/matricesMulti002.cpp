#include <iostream>
using namespace std;

const int MAX = 100;

void multiplicarMatrices(int matrizA[MAX][MAX], int matrizB[MAX][MAX], int resultado[MAX][MAX], int filaA, int columnaA, int columnaB) {
    // Multiplicación de matrices
    for (int i = 0; i < filaA; ++i) {
        for (int j = 0; j < columnaB; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnaA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[MAX][MAX], int fila, int columna) {
    for (int i = 0; i < fila; ++i) {
        for (int j = 0; j < columna; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrizA[MAX][MAX], matrizB[MAX][MAX], resultado[MAX][MAX];
    int filaA, columnaA, filaB, columnaB;

    // Ingresar dimensiones de las matrices
    cout << "Ingrese el número de filas y columnas de la matriz A: ";
    cin >> filaA >> columnaA;
    cout << "Ingrese el número de filas y columnas de la matriz B: ";
    cin >> filaB >> columnaB;

    // Verificar si se pueden multiplicar las matrices
    if (columnaA != filaB) {
        cout << "No se pueden multiplicar las matrices. El número de columnas de la matriz A debe ser igual al número de filas de la matriz B." << endl;
        return 0;
    }

    // Ingresar elementos de la matriz A
    cout << "Ingrese los elementos de la matriz A: " << endl;
    for (int i = 0; i < filaA; ++i) {
        for (int j = 0; j < columnaA; ++j) {
            cout << "Ingrese el elemento A[" << i << "][" << j << "]: ";
            cin >> matrizA[i][j];
        }
    }

    // Ingresar elementos de la matriz B
    cout << "Ingrese los elementos de la matriz B: " << endl;
    for (int i = 0; i < filaB; ++i) {
        for (int j = 0; j < columnaB; ++j) {
            cout << "Ingrese el elemento B[" << i << "][" << j << "]: ";
            cin >> matrizB[i][j];
        }
    }

    // Multiplicar las matrices
    multiplicarMatrices(matrizA, matrizB, resultado, filaA, columnaA, columnaB);

    // Imprimir matriz resultante
    cout << "El resultado de la multiplicación es: " << endl;
    imprimirMatriz(resultado, filaA, columnaB);

    return 0;
}

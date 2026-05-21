#include <iostream>

using namespace std;

void mostrarMatriz(int (*ptrMatriz)[10]);

int main()
{
    int matriz[10][10];
    int i = 0;
    int j = 0;
    int numero = 0;

    while (i < 10) {
        while (j < 10) {
            matriz[i][j] = numero + 1;            
            numero++;
            j++;
        }
        i++;
    }
    int (*ptrMatriz)[10];
    ptrMatriz = matriz;
    mostrarMatriz(ptrMatriz);
    return 0;
}

void mostrarMatriz(int (*ptrMatriz)[10])
{
    int i = 0;
    int j = 0;
    while (i < 10) {
        while ( j < 10) {
            std::cout << ptrMatriz[i][j];            
            j++;
        }
        std::cout << std::endl;
        i++;
    }
}
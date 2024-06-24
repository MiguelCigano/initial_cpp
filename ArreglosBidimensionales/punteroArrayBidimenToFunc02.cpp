#include <iostream>

using namespace std;

void configuraMatriz(int (*ptrM)[5], int n);
void muestraMatriz(int (*ptrM)[5], int n);

int main()
{   

    int dimension = 5;

    int matriz[5][5];

    int (*ptrM)[5];
    ptrM = matriz;

    configuraMatriz(matriz, dimension);
    muestraMatriz(matriz, dimension);

    return 0;
}

void configuraMatriz(int (*ptrM)[5], int dimension)
{
    int i = 0;
    int j = 0;
    int numero = 1;

    while(i < dimension)
    {
        while(j < dimension)
        {
            ptrM[i][j] = numero;
            numero++; 
            j++;
        }
        i++;
        j = 0; //  important no olvidar resetear el valor de j
    }
}

void muestraMatriz(int (*ptrM)[5], int dimension)
{
    int i = 0;
    int j = 0;

    while(i < dimension)
    {
        while(j < dimension)
        {
            std::cout << ptrM[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
        i++;
        j = 0;
    }
}



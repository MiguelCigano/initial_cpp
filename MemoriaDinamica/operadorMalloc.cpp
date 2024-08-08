#include <iostream>
#include <cstdlib>

void mostrarArregloDinamico(int *ptrVec);

int main(int argc, char **argv)
{
    // int *numeros2 = (int *)malloc(sizeof(int)*8);
    /* asignacion de valores usando aritmetica de punteros */

    /* en caso de que se requiera usar "new" */
    int *numeros2 = new int[8];

    *(numeros2) = 20000;
    *(numeros2 + 1) = 20;
    *(numeros2 + 2) = 200;
    *(numeros2 + 3) = 2000;
    *(numeros2 + 4) = 20000;
    *(numeros2 + 5) = 200000;
    *(numeros2 + 6) = 2000000;
    *(numeros2 + 7) = 20000000;

    mostrarArregloDinamico(numeros2);

    delete numeros2;
    // free(numeros2);

    return 0;
}

void mostrarArregloDinamico(int *ptrVec)
{
    for (int i = 0; i < 8; i++){
        std::cout << ptrVec[i] << std::endl;
    }

}


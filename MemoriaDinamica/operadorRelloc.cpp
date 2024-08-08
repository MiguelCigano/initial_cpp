#include <iostream>
#include <cstdlib>

void mostrarArregloDinamico(int *ptrVec);

int main(int argc, char **argv)
{
    int *numeros2 = (int *)malloc(sizeof(int)*8);
    /* asignacion de valores usando aritmetica de punteros */

    /* en caso de que se requiera usar "new" */
    // int *numeros2 = new int[8];

    *(numeros2) = 1;
    *(numeros2 + 1) = 2;
    *(numeros2 + 2) = 3;
    *(numeros2 + 3) = 4;
    *(numeros2 + 4) = 5;
    *(numeros2 + 5) = 6;
    *(numeros2 + 6) = 7;
    *(numeros2 + 7) = 8;

    mostrarArregloDinamico(numeros2);

    int *numeros3 = (int *)realloc(numeros2, sizeof(int)*15);

    /* realloc: entrea un valor en caso de que si se puedo redimensionar y un NULL en caso de que no */

    /* Por lo anterior es necesario hacer la comprobación antes de guardar los valores de nuu */

    if (numeros3 == nullptr){

        std::cout << "asignación de memoria incorrecto" << std::endl;
        free(numeros2);

        return 1;
    }
    else{
        numeros2 = numeros3;
    }

    /* Solo se hace una igualación debido a que nos interesa la dirección de numeros3 */

    mostrarArregloDinamico(numeros2);

    // delete numeros2;
    free(numeros2);

    return 0;
}

void mostrarArregloDinamico(int *ptrVec)
{
    std::cout << std::endl;
    std::cout << " -----  -----  -----" << std::endl;
    
    for (int i = 0; i < 15; i++){
        std::cout << ptrVec[i] << std::endl;
    }

}


/* La línea anterio: *numeros2 = *numeros3; no es correcta en este contexto porque:

Manejo de Punteros: Esta línea está intentando copiar el valor del primer elemento del bloque de memoria apuntado por numeros3 al primer elemento del bloque de memoria apuntado por numeros2. Esto no cambia el puntero numeros2 para que apunte al nuevo bloque de memoria asignado por realloc. */

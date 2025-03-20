/*
    Desmotración de paso de un arreglo a una función con notación de paso por valor y usando punteros. 

    Es importante tener en cuenta que un arreglo no se pasa por valor en C++, solo se usa la notación pero en realidad se está pasando un puntero (int *).
*/

#include <iostream>
#define MAX                 100
#define MAX_IGNORE_CHAR     1000

// usando variables globales
int arreglo[MAX];
static bool flg_break     = true;
static bool flg_temporal  = true;

// definición de prototipos de función
long int mas_grande(int x[], const int length);
long int mas_grande_puntero(int *x, const int length);

int main(int argc, char **argv){
    int i = 0;
    while (flg_break){
        if (i >= MAX) {
            std::cout << "ERROR ACCESS LIMIT ARRAY!" << std::endl;
            return -1;
        }
        std::cout << "Input int value: " << std::endl;
        std::cin >> arreglo[i];
        std::cout << "Continue? to YESS press 1, NO use 0 ---> ";
        std::cin >> flg_temporal;
        // Verificar si la entrada fue válida
        if (std::cin.fail()) {
            std::cin.clear(); // Restablecer el estado de cin
            std::cin.ignore(MAX_IGNORE_CHAR, '\n'); // Descartar la entrada incorrecta
            std::cout << "INVALID INPUT! Please use 1 or 0 in the next time" << std::endl;
            continue;
        }
        i++;
        if (flg_temporal == 1) {
            std::cout << "Valid input, we continue..." << std::endl;
        }
        else if (flg_temporal == 0) {
            flg_break = false;    
        }
        else {
            std::cout << "INVALID!"<< std::endl;
            flg_break = false;
            return -1;
        }
    }

    /* 
        Importante pasar el arreglo sin los corchetes, nota que estás usando un puntero sin darte cuenta, es decir, arreglo es la dirección del primer elmento del arreglo.

        Los argumentos de las funciones deben de ser un solo valor númerico, no una estructura de datos.
    */

    const int length_arreglo = i;
    long int grande = mas_grande_puntero(arreglo, length_arreglo);
    std::cout << "Lenght: " << length_arreglo << std::endl;
    std::cout << "Array's bigger element: " << grande << std::endl;
    
    return 0;
}

/* 
    la manera de pasar el arreglo como argumento es similar a la anterior, notese que se está indicando que el argumento es un apuntador a un entero, "x" en este caso hace la función de un identificador para el ambito de la función
*/


/**
 * @brief Encuentra el valor más grande en un arreglo de enteros.
 *
 * @param x Arreglo de enteros. En realidad, se convierte en un puntero a entero (int*).
 * @param length Longitud del arreglo para evitar desbordamientos.
 * @return El valor más grande encontrado en el arreglo.
 */
long int mas_grande(int x[], const int length){
    long int grande = -12000;
    for(int i = 0; i < length; i++){
        if(x[i] > grande){
            grande = x[i];
        }
    }
    return grande;
}

/* 
    a continuación se muestra una función similar a mas_grande pero pasando punteros como argumentos
*/

/**
 * @brief Encuentra el valor más grande usando punteros.
 *
 * @param x Puntero a un arreglo de enteros.
 * @param length Longitud del arreglo para evitar desbordamientos.
 * @return El valor más grande encontrado en el arreglo.
 */
long int mas_grande_puntero(int *x, const int length){
    long int grande = -12000;
    for(int i = 0; i < length; i ++){
        if(*(x+i) > grande){
            grande = *(x+i);
        }
    }
    return grande;
}
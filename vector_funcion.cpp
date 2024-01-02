/* Desmotración de paso de un arreglo a una función */

#include <iostream>

#define MAX 3

int arreglo[MAX];
int contador;

// definición de prototipo de función
int longuitud(int x[], int y);
int mas_grande(int x[], int y);

int main(){
    std::cout << "Hola 0x001 \n" << std::endl;
    for(int i = 0; i < MAX; i++){
        std::cout << "Ingresa un valor entero" << std::endl;
        std::cin >> arreglo[i];
    }

    // importante pasar el arrelo sin los corchetes, nota que estás usando un puntero sin darte cuenta, es decir, arreglo es la dirección del primer elmento del arreglo

    // los argumentos de las funciones deben de ser un solo valor númerico

    int largo = longuitud(arreglo, MAX);
    std::cout << "Longuitud de arreglo: " <<largo << std::endl;
    //std::cout << arreglo << std::endl;
    //std::cout << &arreglo[0] << std::endl;
    int grande = mas_grande(arreglo, MAX);
    std::cout << "Elemento más grande de arreglo: " << grande << "\n" << std::endl;  
    return 0;
}

// definición de función
int longuitud(int x[], int y){
    
    int leng = 0;

    for(int i = 0; i < y; i++){
            leng += 1;
    }

    return leng;
}

// la manera de pasar el arreglo como argumenot es similar a la anterior, 
// notese que se está indicando que el argumento es un apuntador a un entero, 
// "x" en este caso hace la función de un identificador para el ambito de la 
// función

int mas_grande(int *x, int y){
    int grande = -12000;

    for(int i = 0; i < y; i++){
        if(x[i] > grande){
            grande = x[i];
        }
    }
    return grande;
}

// a continuación se 
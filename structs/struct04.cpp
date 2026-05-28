/* Puntero a estructura 04

*/

#include <iostream>

using namespace std;

// Se crea la variable Led tipo STRUCT la cual contiene tres campos definidos en la estructura LED.
// Además, se crea un puntero el cual almacena la dirección de Led, es decir, a punta a la direccion de memoria de Led.


struct LED{
    int modo;
    int velocidad;
    char nombre[20];
}Led, *puntero_LED = &Led;


// *Definimos dos funciones que no retornan nada, pero pasamos el puntero tipo estructura creado anteriormente.

void pedirDatos();
void mostrarDatos();

int main(){
    pedirDatos();
    mostrarDatos();
    return 0;
}

void pedirDatos(){
    std::cout<<"Digite el nombre del led"<< std::endl;
    cin.getline(puntero_LED->nombre, 20);
    std::cout<<"Digite el modo del Led: "<< std::endl;
    std::cin>>puntero_LED->modo;
}

void mostrarDatos(){
    std::cout<<"Nombre: "<< puntero_LED->nombre << std::endl;
    std::cout<<"Modo: "<< puntero_LED->modo<<std::endl;

}

// Notese que no estoy usando argumentos en las funciones y el programa compila de buena forma.
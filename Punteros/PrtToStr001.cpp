#include <iostream>
#define MAX 10

using namespace std;

// Los punteros a estructuras se usan frecuentemente cuando se pasa
// una estructura como argumento a una función.

// Los punteros a estructuras tambien se usan en un método de almacenamiento de datos muy poderoso,
// conocido como listas encadenadas.

struct Parte
{
    int numero;
    char nombre[MAX];
};

// ahora se declara un apuntador al tipo Parte

struct Parte *ptrParte;

int main(void)
{
    Parte rueda;
    ptrParte = &rueda;

    (*ptrParte).numero = 100;

    std::cout<<"Digite el nombre de la parte"<< std::endl;
    cin.getline(ptrParte->nombre, MAX);

    ptrParte->numero = 100 + 3;

    std::cout << std::endl;
    

    std::cout << (*ptrParte).numero << std::endl;
    std::cout << ptrParte->nombre << std::endl;
    
    return 0;
}
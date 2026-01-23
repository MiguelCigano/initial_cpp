#include <iostream>
#define MAX 10

/**
 * Los punteros a estructuras se usan frecuentemente cuando se pasa
 * una estructura como argumento a una función.
 * 
 * Los punteros a estructuras tambien se usan en un método de almacenamiento de datos muy poderoso,
 * conocido como listas encadenadas.
*/

struct Parte {
    int numero;
    char nombre[MAX];
};

// se declara un apuntador al tipo Parte de forma global
struct Parte *ptr_parte;

int main(int argc, char **argv)
{
    Parte rueda;
    ptr_parte = &rueda;
    (*ptr_parte).numero = 100;

    std::cout << "Input name part: "    << std::endl;
    std::cin.getline(ptr_parte->nombre, MAX);
    ptr_parte->numero = 100 + 3;
    
    std::cout << (*ptr_parte).numero    << std::endl;
    std::cout << ptr_parte->nombre      << std::endl;
    
    return 0;
}
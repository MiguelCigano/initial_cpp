#include <iostream>

/*
 * ~ Copiar un array dinámico
 * 1. Solicite al usuario el tamano de un array de enteros.
 * 2. Reserve memoria dinámica para almacenarlo.
 * 3. Permita la usuario ingresar valores.
 * 4. Cree una copia exacta del array en otra dirección de memoria.
 * 
*/

int* mem_requestVector(int *lenght) {
    int *vect = new int [*lenght];
    std::cout << std::endl;
    std::cout << &vect << std::endl;
    return vect;
}

void mem_freeVector(int *vect, int *lenght) {
    // for (int i = 0; i < *lenght; i++) {
    delete[] vect;
    // }
}

void set_valuesVector(int *vect, int *lenght) {
    for (int i = 0; i < *lenght; i++) {
        std::cout << "enter position value ["<< i <<"] : ";
        std::cin >> vect[i];
    }
    std::cout << std::endl;
}

void show_valuesVector(int *vect, int *length) {
    std::cout << "Addres: " << vect << std::endl;
    for (int i = 0; i < *length; i++) {
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

void copy_valuesVector(int *vector, int *vector_copy, int length) {
    for (int i = 0; i < length; i++) {
        vector_copy[i] = vector[i];
    }
}

int main(int argc, char ** argv) 
{
    int length;
    std::cout << "Ingresa tamano de vector: ";
    std::cin >> length;
    if (length <= 0) {
        std::cout << "Error, debe ser un valor mayor igual que cero" << std::endl;
        return 1;
    }

    int *vector = mem_requestVector(&length);
    set_valuesVector(vector, &length);
    show_valuesVector(vector, &length);

    int *vector2 = mem_requestVector(&length);
    copy_valuesVector(vector, vector2, length);
    show_valuesVector(vector2, &length);

    mem_freeVector(vector2, &length);
    mem_freeVector(vector, &length);

    return 0;
}
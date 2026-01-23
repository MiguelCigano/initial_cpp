// Revisando el uso de punteros para acceder a valores de un arreglo

#include <iostream>

const int lenght = 5;

int main(int argc, char **argv) {

    const int array_n[lenght] = {1, 2, 3, 4, 5};
    
    std::cout << *array_n << std::endl;
    std::cout << &array_n[0] << std::endl;
    std::cout << array_n << std::endl;
    
    std::cout << *(array_n + 1) << std::endl;
    std::cout << &array_n[1] << std::endl;
    std::cout << array_n + 1 << std::endl;
    
    std::cout << *(array_n + 2) << std::endl;
    std::cout << &array_n[2] << std::endl;
    std::cout << array_n + 2 << std::endl;

    return 0;
}

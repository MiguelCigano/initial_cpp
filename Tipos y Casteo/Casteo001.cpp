#include <iostream>

int main() {
    // Definir un arreglo de enteros
    unsigned char arregloEnteros[] = {1, 2, 3, 4, 5};

    // Castear el arreglo a un puntero de tipo void
    void* punteroVoid = static_cast<void*>(arregloEnteros);

    // Castear de nuevo a un puntero de tipo entero
    uint16_t* punteroEntero = static_cast<uint16_t*>(punteroVoid);
     // Castear el arreglo a un puntero de tipo float
    //uint16_t* punteroFloat = reinterpret_cast<uint16_t*>(arregloEnteros);

    // Imprimir los elementos del arreglo usando el puntero
    for (int i = 0; i < 5; ++i) {
        std::cout << "Elemento " << i << ": " << punteroEntero[i] << std::endl;
    }

    return 0;
}
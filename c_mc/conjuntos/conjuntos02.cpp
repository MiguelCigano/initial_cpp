#include <iostream>
#include <vector>

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5};
    std::vector<int> B = {10, 20, 30, 40, 50};

    /**
     * for (auto x : A) -> lectura (copia de cada elemento para leerlo).
     * for (const auto &x : A) -> lectura eficiente (sin copia, sin modificar).
     * 
     * for (auto &x : A) -> modificadora (referencia de cada elemento).
     */
    // Lee (usando auto)
    for (auto x : A) {
        std::cout << x << " ";
    }
    std::cout << std::endl; // solo es para generar un salto de línea

    // Modifica (usando auto&)
    for (auto &x : A) {
        // x = x + 10;
        x += 10; // lo mismo que la línea anterior (x = x + 10)
    }

    /**
     * size_t : es recomentable usar cuando trabajamos con indices
     * size() : es un metodo de la clase vector que nos da la dimensión del contenedor
     */
    // Modifica por indice (size_t)
    for (size_t i = 0; i < B.size(); ++i) {
        B[i] = B[i] - 1; 
    }

    // Accede (Lee) por indice (size_t)
    for (size_t i = 0; i < B.size(); ++i) {
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
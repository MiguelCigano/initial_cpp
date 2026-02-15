#include <iostream>
#include <vector>
#include <utility> // std::pair

/**
 * @brief Genera una relación R a partir de dos conjuntos A y B.
 *
 * Esta función construye el conjunto R de pares ordenados (a, b) tales que
 * a pertenece al conjunto A, b pertenece al conjunto B, además se cumple
 * una cierta condición (en este caso, a < b).
 * 
 * Aunque pueda parecer compleja, esta función es principalmente de lectura:
 * los elementos de A y B se recorren para crear un nuevo vector de pares llamado R.
 * Los elementos originales de A y B no se modifican, por lo que se utilizan
 * referencias constantes (const &) tanto en los parámetros como en los bucles "for".
 *
 * @param A Conjunto de elementos enteros.
 * @param B Conjunto de elementos enteros.
 * @return std::vector<std::pair<int, int>> Un vector de pares ordenados (a, b) 
 * que cumplen una relación.
 *
 * @note La relación implementada actualmente es: { a < b }.
 * Puede modificarse la condición dentro del "if" para definir otras relaciones.
 */
std::vector<std::pair<int, int>> relationship_auto(const std::vector<int> &A, const std::vector<int> &B) {
    std::vector<std::pair<int, int>> R;

    for (const auto &a : A) {
        for (const auto &b : B) {
            if (a < b) {
                R.push_back({a, b});
            }
        }
    }
    return R;
}

int main() {
    std::vector<int> A = {1, 2, 3, 4};
    std::vector<int> B = {1, 2, 3, 4};

    std::vector<std::pair<int, int>> R = relationship_auto(A, B);

    // Leer la relación
    std::cout << "Relacion R = {(a,b) | a < b v4} : " << std::endl;
    for (auto p : R) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
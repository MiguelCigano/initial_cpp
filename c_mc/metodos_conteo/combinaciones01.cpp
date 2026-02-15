#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

// Limite: factorial_(20)
long long factorial_(const int n) {
    long long f = 1;

    for (size_t k = 1; k <= n; k++) { // nota que uso size_t en lugar
        f = k * f;                    // de int
    }
    
    return f;
}

long long combinations(const int n, const int r) {
    return factorial_(n) / (factorial_(r) * factorial_(n - r));
}

void print_num_combinations(const long long &c) {
    std::cout << "Combinations01: " << c << std::endl;
}


int main() {
    std::vector<std::string> X = {"A","B","C","D","E"};
    int n = X.size(); // Para obtener el tamaño de X
    int r = 3;

    long long c = combinations(n, r);
    print_num_combinations(c);

    // Uso una técnica de enmascaramiento (mask), la cual
    // consiste en usar un contenedor tipo vector el cual es llenado
    // con ceros y unos, los cuales me indican de que objetos 
    // me interesa obtener las combinaciones
    std::vector<bool> mask(n);
    fill(mask.begin(), mask.begin() + r, true); // r unos y (n-r) ceros
                                                // Ejemplo con n=5, r=3
                                                // {1, 1, 1, 0, 0}

    do {
        // Imprimir la combinación actual
        for (size_t i = 0; i < X.size(); i++) {
            if (mask[i] == 1) { // Si la máscara es true en esta posición
                std::cout << X[i] << " "; // Imprime el elemento X[i]
            }
        }
        std::cout << std::endl;

    } while (prev_permutation(mask.begin(), mask.end()));

    return 0;
}

#include "factorial01.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

// Esta funcion no esta optimizada, puede tener overflow en el factorial
// Recomendación: evitar el uso de factorial para un numero mayor a 10
long long permutations(const int n, const int r) {
    return factorial_(n) / factorial_(n - r);
}

void print_num_permutations(const long long &p) {
    std::cout << "Permutations2: "<< p << std::endl;
}

void print_permutations(std::vector<std::string> X) {
    do {
        for (const std::string &x : X) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

    } while(next_permutation(X.begin(), X.end()));
}

int main() {

    // Conjunto de 5 elementos
    std::vector<std::string> GX = {"A", "B", "C", "D", "E"};

    // Secuencia de 3 elementos del conjunto GX
    std::vector<std::string> X = {"A", "B", "C"};

    long long p = permutations(5, 3);
    print_num_permutations(p);
    print_permutations(X);

    return 0;
}

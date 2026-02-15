#include <iostream>
#include <algorithm>
#include <limits>

// Limite: factorial_(20)
long long factorial_(const int n) {
    long long f = 1;

    for (size_t k = 1; k <= n; k++) {
        f = k * f;
    }
    
    return f;
}

// Función no optimizada, puede tener overflow en el factorial
// Función asegura que r sea mayor a 0 y menor que n para poder operar.
// En caso de no cumplir lo anterior, el resultado es un 0.
// Función considera el caso en que r = 0, el resultado es 1
// Recomendación: evitar el uso de factorial para un número mayor a 19
long long permutations(const int n, const int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    return factorial_(n) / factorial_(n - r);
}

// Funcion optimizada, evita el uso excesivo de factorial, en su lugar usa la ley de producto.
// Función asegura que r sea mayor a 0 y menor que n para poder operar.
// En caso de no cumplir lo anterior, el resultado es un 0.
// Función considera el caso en que r = 0, el resultado es 1
long long permutations_opt(const int n, const int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    long long result = 1;
    for (size_t i = 0; i < r; i++) {
        result = result * (n - i);
    }
    return result;
}

void print_num_permutations(const long long &p) {
    std::cout << "Permutations04: "<< p << std::endl;
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
    std::vector<std::string> GX = {"B", "E", "B", "E"};

    // Secuencia de 3 elementos del conjunto GX
    std::vector<std::string> X = {"B", "E", "B", "E"};

    // Tu eliges cual función quieres usar:
    long long p = permutations_opt(4, 4);
    // long long p = permutations(5, 3);

    print_num_permutations(p);
    print_permutations(X);

    return 0;
}

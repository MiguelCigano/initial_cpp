#include "factorial01.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

long long combinations(const int n, const int r) {
    return factorial_(n) / (factorial_(r) * factorial_(n - r));
}

void print_num_combinations(const long long &c) {
    std::cout << "Combinations02: " << c << std::endl;
}


int main() {
    std::vector<std::string> X = {"B", "E", "B", "E"};
    int n = X.size();
    int r = 4;

    long long c = combinations(n, r);
    print_num_combinations(c);

    std::vector<bool> mask(n);
    fill(mask.begin(), mask.begin() + r, true); // r unos y (n-r) ceros

    do {
        // Imprimir la combinación actual
        for (size_t i = 0; i < X.size(); i++) {
            if (mask[i] == 1) {
                std::cout << X[i] << " ";
            }
        }
        std::cout << std::endl;

    } while (prev_permutation(mask.begin(), mask.end()));

    return 0;
}

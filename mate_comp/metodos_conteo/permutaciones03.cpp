#include "factorial01.hpp"
#include <iostream>
#include <algorithm>

long long factorial_(const int n) {
    long long f = 1;

    for (size_t k = 1; k <= n; k++) {
        f = k * f;
    }
    
    return f;
}


int main() {
    std::vector<std::string> X = {"A", "B", "C"};
    // std::vector<int> X = {1, 2, 3};

    std::cout << "Permutaciones de {A, B, C}" << std::endl;
    do {
        for (const std::string &x : X) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } while(std::next_permutation(X.begin(), X.end()));

    return 0;
}
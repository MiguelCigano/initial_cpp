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
    std::cout << "Combinations03: " << c << std::endl;
}

int main() {

    int n = 8;
    int r = 3;

    long long c = combinations(n, r);
    print_num_combinations(c);

    return 0;
}

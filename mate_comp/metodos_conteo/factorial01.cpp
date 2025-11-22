#include "factorial01.hpp"

// Limite: factorial_(20)
long long factorial_(const int n) {
    long long f = 1;

    for (size_t k = 1; k <= n; k++) {
        f = k * f;
    }
    
    return f;
}
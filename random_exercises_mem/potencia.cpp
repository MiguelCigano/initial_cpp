#include <iostream>

double potencia(long base, long exponent = 2){
    if (exponent == 2) { 
        return (base*base);
    }
    else {
        double res = base;
        for (long i = 1; i < exponent; i++) {
            res *= base;
        }
        return res;
    }
}

int main() {
    std::cout << "potencia(3) = "<< potencia(3) << std::endl;
    std::cout << "potencia (3, 5) = " << potencia(3, 5) << std::endl; 
}
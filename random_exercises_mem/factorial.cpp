#include <iostream>

// prototype
int factorial(const int n);

int main() {
    const int n = 5;
    int fact = factorial(n);
    std::cout << "Factorial of " << n << " is " << fact << std::endl;
    return 0;
}

int factorial(const int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}
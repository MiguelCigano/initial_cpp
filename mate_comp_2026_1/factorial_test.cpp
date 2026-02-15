#include <iostream>

// Limit to n = 20
void factorial(const int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
}

int main () {
    int n = 5;
    factorial(n);
    return 0;
}


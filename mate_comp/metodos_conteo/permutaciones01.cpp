#include <iostream>
#include <limits>

/**
 * Explicación del Do-While
 * do {
 * 
 *  // Operación a realizar al menos una vez
 * 
 * } while (condicion)
 */
int main() {
    
    std::cout << "Max long long: " << std::numeric_limits<long long>::max() << std::endl;
    std::cout << "Max int: " << std::numeric_limits<int>::max() << std::endl;

    int x = 1;
    do {
        std::cout << "Value x = " << x << std::endl;
        x = x + 1;
        // x++; Lo mismo que la linea anterior
    } while (x <= 5);

    return 0;
}
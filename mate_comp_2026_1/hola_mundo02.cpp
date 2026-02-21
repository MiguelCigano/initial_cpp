#include <iostream>

int main() {
    int x;  // Definition
    x = 10; // Initialization
    
    // int x = 10; // Definition with Initialization

    std::cout << "Value x is: " << x << std::endl;
    std::cout << "Address x is: " << &x << std::endl;

    x = x + 1; // Assignment

    std::cout << "New value x: " << x << std::endl;

    return 0;
}

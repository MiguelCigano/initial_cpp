#include <iostream>
int a = 2;
int b = 5;

int suma_fn() {
    int result;
     // local variable
    result = a + b;
    std::cout << result << std::endl;
    return result;
}


int main() {
    int result = suma_fn();
    std::cout << "Hello CUT" << std::endl;
    std::cout << result << std::endl;
    return 0;
}

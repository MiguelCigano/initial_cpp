#include<iostream>

int modified_by_value(int x) {
    x = x + 1;
    std::cout << "Value x in fn: " << x << std::endl;
    std::cout << "Address x in fn: " << &x << std::endl;
    return x;
}

int main() {
    int x = 10; // Definition and Initialization
    int result; // Just Definition
    
    result = modified_by_value(x);

    std::cout << "Value x in main: " << x << std::endl;
    std::cout << "Address x in main: " << &x << std::endl;

    std::cout << "Result is: " << result << std::endl;

    return 0;
}
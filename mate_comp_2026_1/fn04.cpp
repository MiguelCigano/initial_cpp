#include <iostream>

int fn_square(int x) {
    x = x * x;
    std::cout << "Value x in fn_square is: " << x << std::endl;
    std::cout << "Address x in fn_square is: " << &x << std::endl;
    return x;
}

void fn_print() {
    std::cout << "Hello from fn_print()!" << std::endl;
}

int main() {
    int x = 10;
    int result;
    std::cout << "Value x in main is: " << x << std::endl;
    std::cout << "Address x in main is: " << &x << std::endl;
    
    fn_print();
    result = fn_square(x);

    std::cout << "Result x * x is: " << result << std::endl;

    return 0;
}



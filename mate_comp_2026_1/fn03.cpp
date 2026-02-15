#include <iostream>

int fn_square(int x) {
    x = x * x; // print 100
    std::cout << "Value x in fn_square is: " << x << std::endl;
    std::cout << "Address x in fn_square is: " << &x << std::endl;
    return x;
}

void fn_print() {
    std::cout << "Hello from fn_print()!" << std::endl;
} // Implicit return

int main() {
    int x = 10;
    std::cout << "Value x in main is: " << x << std::endl;
    std::cout << "Address x in main is: " << &x << std::endl;
    
    fn_print();
    fn_square(x);

    std::cout << "Result x * x is: " << x << std::endl;  // print 10

    return 0;
}



#include<iostream>

void modified_by_reference(int &x) {
    x = x + 1;
}

void print_value(const int &x) {
    std::cout << "read x in fn: " << x << std::endl;
}

int main() {
    int x = 10;

    // modificar valor
    modified_by_reference(x);
    
    // leer valor
    print_value(x);

    std::cout << "x in main: " << x << std::endl;

    return 0;
}
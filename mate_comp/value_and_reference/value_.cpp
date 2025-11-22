#include<iostream>

void modified_by_value(int x) {
    x = x + 1;
    std::cout << "x in fn: " << x << std::endl;
    std::cout << "x in fn address: " << &x << std::endl;
}

int main() {
    int x = 10;
    modified_by_value(x);

    std::cout << "x in main: " << x << std::endl;
    std::cout << "x in main address: " << &x << std::endl;

    return 0;
}
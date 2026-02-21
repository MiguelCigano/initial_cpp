#include <iostream>

int main() {
    int x = 10;
    int *ptr = &x;

    std::cout << "\n|  Variables and pointers  |" << std::endl;
    std::cout << "Value of x: "     << *ptr << std::endl; 
    std::cout << "Address of x: "   <<  ptr << std::endl;
    std::cout << "Address of x: "   <<   &x << std::endl;
    std::cout << "Address of ptr: " << &ptr << std::endl;

    std::cout << "\n|  Arrays  |" << std::endl;
    int a[3] = {1, 20, 3};

    std::cout << "Value of a[0]: "   << a[0]  << " (same *a: " << *a << ")" << std::endl;
    std::cout << "Address of a: "    << a     << std::endl; // similar to ptr
    std::cout << "Address of a[0]: " << &a[0] << std::endl; // similar to &ptr

    // Show 4 Bytes for Int
    std::cout << "Address of a[1]: " << &a[1] << " (a + 4 Bytes)" << std::endl;
    std::cout << "Address of a[2]: " << &a[2] << " (a + 8 Bytes)" << std::endl;

    return 0;
}


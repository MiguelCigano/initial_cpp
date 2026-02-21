#include <iostream>

typedef uint8_t ui8;

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

    std::cout << "Value of a[0]: " << a[0]  << " (same *a: " << *a << ")" << std::endl;
    std::cout << "Address of a: "     << a     << std::endl; // similar ptr
    std::cout << "Address of a[0]: "  << &a[0] << std::endl; // similar &ptr
    std::cout << "Address of a[0_1]: " << (void*)((ui8*)&a[0] + 1)  << std::endl;
    std::cout << "Address of a[0_2]: " << (void*)((ui8*)&a[0] + 2)  << std::endl;
    std::cout << "Address of a[0_3]: " << (void*)((ui8*)&a[0] + 3)  << std::endl;

    // Show 4 Bytes for Int
    std::cout << "Address of a[1_0]: " << &a[1] << " (a + 4 Bytes)" << std::endl;
    std::cout << "Address of a[1_1]: " << (void*)((ui8*)&a[1] + 1)  << std::endl;
    std::cout << "Address of a[1_2]: " << (void*)((ui8*)&a[1] + 2)  << std::endl;
    std::cout << "Address of a[1_3]: " << (void*)((ui8*)&a[1] + 3)  << std::endl;
    
    std::cout << "Address of a[2_0]: " << &a[2] << " (a + 8 Bytes)" << std::endl;
    std::cout << "Address of a[2_1]: " << (void*)((ui8*)&a[2] + 1)  << std::endl;
    std::cout << "Address of a[2_2]: " << (void*)((ui8*)&a[2] + 2)  << std::endl;
    std::cout << "Address of a[2_3]: " << (void*)((ui8*)&a[2] + 3)  << std::endl;

    return 0;
}


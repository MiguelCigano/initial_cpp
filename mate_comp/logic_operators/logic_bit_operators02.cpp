#include <iostream>
#include <bitset>
#include <cstdint>  // Para tipos enteros de tamaño específico

int main() {
    uint8_t a = 0b10101010;  // 8 bits, sin signo
    uint8_t b = 0b11001100;
    
    std::cout << "a = " << std::bitset<8>(a) << " (" << (int)a << ")" << std::endl;
    std::cout << "b = " << std::bitset<8>(b) << " (" << (int)b << ")" << std::endl;
    
    std::cout << "\nOPERACIONES:" << std::endl;
    std::cout << "a & b = " << std::bitset<8>(a & b) << std::endl;
    std::cout << "a | b = " << std::bitset<8>(a | b) << std::endl;
    std::cout << "a ^ b = " << std::bitset<8>(a ^ b) << std::endl;
    std::cout << "~a    = " << std::bitset<8>(~a) << " (" << (int)(~a) << ")" << std::endl;
    
    return 0;
}

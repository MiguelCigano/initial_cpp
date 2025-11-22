#include <iostream>
#include <bitset>

int main(){
    unsigned char a = 0b10101010; // numero 170
    unsigned char b = 0b11001100; // numero 204
    
    std::cout << "a = " << std::bitset<8>(a) << " (" << (int)a << ")" << std::endl;
    std::cout << "b = " << std::bitset<8>(b) << " (" << (int)b << ")" << std::endl;
    
    std::cout << "a & b = "  << std::bitset<8>(a & b) << std::endl;
    std::cout << "a | b = "  << std::bitset<8>(a | b) << std::endl;
    std::cout << "a ^ b = "  << std::bitset<8>(a ^ b) << std::endl;

    unsigned char c = 0b00001111;
    unsigned char mask = 0b00000100;
    c &= ~(mask);
    std::cout <<"c = " << std::bitset<8>(c) << std::endl;
    
    unsigned char d = 0b00000001;
    d = (d << 3);
    std::cout <<"d = " << std::bitset<8>(d) << std::endl;

    return 0;
}

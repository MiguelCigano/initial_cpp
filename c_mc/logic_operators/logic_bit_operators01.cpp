#include <iostream>
#include <bitset>
#include <iomanip>

// Función para mostrar números en binario
void mostrar_binario(int num, const std::string& nombre) {
    std::cout << nombre << " = " << std::setw(3) << num 
              << " = " << std::bitset<8>(num) << std::endl;
}

// Función para mostrar operación bit a bit
void mostrar_operacion(int a, int b, int resultado, 
                       const std::string& operador, const std::string& simbolo) {
    std::cout << "\n--- " << operador << " (" << simbolo << ") ---" << std::endl;
    mostrar_binario(a, "a");
    mostrar_binario(b, "b");
    std::cout << "         " << std::string(8, '-') << std::endl;
    mostrar_binario(resultado, "result");
}

int main() {
    // Valores de ejemplo
    int a = 0b11001100;  // 204 en decimal
    int b = 0b10101010;  // 170 en decimal
    
    std::cout << "=== OPERADORES BIT A BIT ===" << std::endl;
    
    // Mostrar los valores originales
    mostrar_binario(a, "a");
    mostrar_binario(b, "b");
    
    // AND bit a bit (&)
    int and_result = a & b;
    mostrar_operacion(a, b, and_result, "AND bit a bit", "&");
    
    // OR bit a bit (|)
    int or_result = a | b;
    mostrar_operacion(a, b, or_result, "OR bit a bit", "|");
    
    // XOR bit a bit (^)
    int xor_result = a ^ b;
    mostrar_operacion(a, b, xor_result, "XOR bit a bit", "^");
    
    // NOT bit a bit (~)
    int not_a = ~a;
    int not_b = ~b;
    std::cout << "\n--- NOT bit a bit (~) ---" << std::endl;
    mostrar_binario(a, "a");
    mostrar_binario(not_a, "~a");
    mostrar_binario(b, "b");
    mostrar_binario(not_b, "~b");
    
    // Desplazamientos
    std::cout << "\n=== DESPLAZAMIENTOS ===" << std::endl;
    
    // Desplazamiento a la izquierda (<<)
    int shift_left = a << 2;
    std::cout << "\n--- Desplazamiento izquierda (<< 2) ---" << std::endl;
    mostrar_binario(a, "a");
    mostrar_binario(shift_left, "a << 2");
    std::cout << "Nota: Equivale a multiplicar por 2^2 = 4" << std::endl;
    
    // Desplazamiento a la derecha (>>)
    int shift_right = a >> 2;
    std::cout << "\n--- Desplazamiento derecha (>> 2) ---" << std::endl;
    mostrar_binario(a, "a");
    mostrar_binario(shift_right, "a >> 2");
    std::cout << "Nota: Equivale a dividir por 2^2 = 4" << std::endl;
    
    // Ejemplos prácticos
    std::cout << "\n=== EJEMPLOS PRÁCTICOS ===" << std::endl;
    
    // 1. Verificar si un bit está encendido
    int numero = 0b10101010;  // 170
    int bit_pos = 3;          // Queremos verificar el bit en posición 3 (4to bit desde la derecha)
    bool bit_encendido = (numero >> bit_pos) & 1;
    std::cout << "En " << std::bitset<8>(numero) << ", el bit en posición " 
              << bit_pos << " está: " << (bit_encendido ? "ENCENDIDO" : "APAGADO") << std::endl;
    
    // 2. Encender un bit específico
    int numero2 = 0b10101010;
    int pos_encender = 1;
    int numero_encendido = numero2 | (1 << pos_encender);
    std::cout << "Encender bit " << pos_encender << " en " << std::bitset<8>(numero2) 
              << " = " << std::bitset<8>(numero_encendido) << std::endl;
    
    // 3. Apagar un bit específico
    int pos_apagar = 7;
    int numero_apagado = numero2 & ~(1 << pos_apagar);
    std::cout << "Apagar bit " << pos_apagar << " en " << std::bitset<8>(numero2) 
              << " = " << std::bitset<8>(numero_apagado) << std::endl;
    
    return 0;
}
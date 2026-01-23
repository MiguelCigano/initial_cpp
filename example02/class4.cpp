#include <iostream>

// declaracion de estructura
struct Persona {
    int edad;
    bool mayoriaEdad;
};

enum Animal {
    RAZA,  // inicia en 0
    HABITAD,
};

// inicializacion de estructura
Persona abraham = {24, true};

// prototipo de funcion (firma de funcion)
void disminuye_edad(Persona *ab) {
    std::cout << "edad:" << ab->edad << std::endl;
    ab->edad = ab->edad - 7;
    std::cout << "edad:" << ab->edad << std::endl;
}

int main() {
    disminuye_edad(&abraham);
    if (RAZA == 1) {
        std::cout << "soy raza 0" << std::endl;
    }
    return 0;
}

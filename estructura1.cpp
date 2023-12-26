// Punteros a estructuras 1
#include <iostream>

struct PERSONA{
    char nombre[20];
    uint16_t edad;
};

// prototipo de función
void pedirDatos(struct PERSONA *puntero_persona);
void mostrarDatos(struct PERSONA *puntero_persona);

int main(){

    PERSONA *puntero_persona = new PERSONA;
    
    pedirDatos(puntero_persona);
    mostrarDatos(puntero_persona);
    std::cin.get();

    return 0;
}

void pedirDatos(struct PERSONA *puntero_persona){
    std::cout << "Nombre de la persona: " << std::endl;
    std::cin >> puntero_persona -> nombre;
    std::cout << "Edad de la persona: " << std::endl;
    std::cin >> puntero_persona -> edad;
}

void mostrarDatos(struct PERSONA *puntero_persona){
    std::cout << puntero_persona -> nombre << std::endl;
    std::cout << puntero_persona -> edad << std::endl;
}
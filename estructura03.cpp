// Punteros a estructuras 3
#include <iostream>

struct PERSONA{
    char nombre[20];
    uint16_t edad;
} *puntero_persona;

// prototipo de función
void pedirDatos();
void mostrarDatos(struct PERSONA *puntero_persona);

int main(){

    PERSONA *puntero_persona = new PERSONA;

    pedirDatos();
    mostrarDatos(puntero_persona);
    std::cin.get();
    
    return 0;
}

void pedirDatos(){
    std::cout << "Nombre de la persona: " << std::endl;
    std::cin >> puntero_persona -> nombre;
    std::cout << "Edad de la persona: " << std::endl;
    std::cin >> puntero_persona -> edad;
}

void mostrarDatos(struct PERSONA *puntero_persona){
    std::cout << puntero_persona -> nombre << std::endl;
    std::cout << puntero_persona -> edad << std::endl;
}
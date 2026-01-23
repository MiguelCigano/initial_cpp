#include <iostream>

struct PERSONA{
    char nombre[20];
    int *edad;
};

// prototipo de función
void set_data(struct PERSONA *pPersona);
void show_data(struct PERSONA *pPersona);

void set_data(struct PERSONA *pPersona){
    std::cout << "Nombre de la persona: " << std::endl;
    std::cin >> pPersona->nombre;
    pPersona->edad = new int;   // retorna una direccion de mm
    std::cout << "Edad de la persona: " << std::endl;
    std::cin >> *(pPersona->edad);
}

void show_data(struct PERSONA *pPersona){
    std::cout << pPersona->nombre << std::endl;
    std::cout << *(pPersona->edad) << std::endl;
}

int main(int argc, char **argv){

    PERSONA *pPersona = new PERSONA;
    set_data(pPersona);
    show_data(pPersona);
    std::cin.get();

    delete pPersona->edad;
    delete pPersona;
    return 0;
}
#include <iostream>
constexpr int kMax = 10;

/**
 * Este ejemplo pasa un struct a una función usando punteros, es decir, hay 
 * un puntero apuntando a un struct.
 * 
 * No se usa memoria dinámica.
 * 
 * TODO: considera el uso una referencia en lugar de un puntero a estructura.
 */

struct Part {
    int number;
    char name[kMax];
};

void set_name_part(Part *part) {
    if (!part) {
        std::cerr << "ERROR: puntero a Part es un nullptr!" << std::endl;
        return;
    }
    std::cout << "Digite el nombre de la parte: " << std::endl;
    // std::cin.ignore();  // review
    std::cin.getline(part->name, kMax);
}

void reset_number_part(Part *part, const int number) {
    if (!part) {
        std::cerr << "ERROR: puntero a Part es un nullptr!" << std::endl;
        return;
    }
    (*part).number = number; // ->
}

int main(int argc, char **argv)
{
    // declaración de un tipo Part, e inicialización con valores
    Part wheel = {0, ""};
    // declaración de puntero a tipo Part
    Part *part_ptr;
    // inicialización de puntero
    part_ptr = &wheel;
    const int var = 1;

    (*part_ptr).number = 100;  // ->
    set_name_part(part_ptr);
    reset_number_part(part_ptr, var);
    std::cout << "Number: " << (*part_ptr).number << std::endl;
    std::cout << "Name: "   <<   part_ptr->name   << std::endl;
    
    return 0;
}
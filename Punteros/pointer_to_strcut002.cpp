#include <iostream>
const int kmax = 10;

// pasando estructura a funcion usando punteros, cuando hay un puntero apuntando al struct
// No se está usando memoria dinámica
// se podría pasar la estructura usando una referencia cuando no tenemos un puntero a struct

struct Part {
    int number;
    char name[kmax];
};

void set_name_part(Part *part) {
    std::cout << "Digite el nombre de la parte: " << std::endl;
    // std::cin.ignore();  // review
    std::cin.getline(part->name, kmax);
}

void reset_number_part(Part *part, const int number) {
    (*part).number = number; 
}

int main(int argc, char **argv)
{
    Part wheel;
    Part *part_ptr;
    part_ptr = &wheel;  // inicializacion del ptr
    const int var = 1;
    (*part_ptr).number = 100;
    
    set_name_part(part_ptr);
    reset_number_part(part_ptr, var);

    std::cout << "Number: " << (*part_ptr).number << std::endl;
    std::cout << "Name: "   << part_ptr->name     << std::endl;
    
    return 0;
}
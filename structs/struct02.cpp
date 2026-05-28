#include <iostream>
#include <iomanip>

typedef struct{
    char carrera[20];
    int matematicas;
    int fisica;
    int ingles;

} NOTAS;

struct ESTUDIANTES{
    int id;
    char nombre[20];
    char gen;
    int edad;
    float promedio;
    char direccion[30];

};

// declaración de la variable tipo estructura
// struc nombre_estructura nombre_variable_tipo_estructura
// https://learn.microsoft.com/es-es/cpp/cpp/struct-cpp?view=msvc-170

// la forma para referencia a un miembro de la estructura es
// struct nombre_variable.nombre_miembro

// incialización de variable tipo estructura
NOTAS notae3 = {"electronic", 10, 9, 8};
// en C++ no es necesario usar la palabra clave struct
struct ESTUDIANTES estudiante1;


int main(){

    std::cout << "mi primera estructura" << std::endl;

    return 0;
}
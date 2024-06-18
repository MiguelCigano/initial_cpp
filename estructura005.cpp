#include <iostream>

using namespace std;

// Estructuras simples

// Ejemplo 1
// Declara una PLANTILLA de estructura llamada RFC

struct RFC {
    char noombre;
    char apellido;
    int edad = 9;
};

RFC *papelP = nullptr;

// Ejemplo 2 
// Declara una ESTRUCTURA llamada fecha y una INSTANCIA llamada fecha actual

struct fecha {
    char mes[2];
    char dia[2];
    char ann[4];
} fecha_actual;

// Ejemplo 3
// Declara una ESTRUCTURA llamada tiempo con una INSTANCIA llamada tiempo inicializada

una de las cosas mas interesantes que podemos hacer  ahora tenemso una de las coasa  que 

struct tiempo {
    int horas;
    int minutos;
    int segundos;
} hora_actual = {8, 5, 0};

// Un rectangulo será definido 
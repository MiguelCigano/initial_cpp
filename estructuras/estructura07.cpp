
/*
** Paso de estructura por valor
*/

#include <iostream>

struct Cat {
    std::string nombre;
    int edad;
};

void sumaEdad(Cat g);

int main (int argc, char** argv)
{
    Cat gato;
    gato.nombre    = "juancho";
    gato.edad      = 10;

    std::cout << "La edad de Juancho  es: " << gato.edad << std::endl;
    sumaEdad(gato);
    std::cout << "La edad de Juancho  es: " << gato.edad << std::endl;

    return 0;
}

void sumaEdad(Cat g)
{
    int a = 2;
    g.edad = g.edad + a;
    std::cout << "Nueva edad de juancho: " << g.edad << std::endl;
}
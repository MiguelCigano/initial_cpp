/*
** Paso de estructura por puntero
*/

#include <iostream>

struct Cat {
    std::string nombre;
    int edad;
};

void sumaEdad(Cat *&g);

int main (int argc, char** argv)
{
    Cat *gato       = new Cat;
    gato->nombre    = "juancho";
    gato->edad      = 10;

    Cat *gato02     = new Cat;
    gato02->nombre  = "benito";
    gato02->edad    = 7;

    /* Copiamos los datos de juancho hacia benito */
    gato02->nombre = gato->nombre;
    gato02->edad = gato->edad;

    std::cout << "La edad de Juancho  es: " << gato->edad << std::endl;
    sumaEdad(gato);
    std::cout << "La edad de Juancho  es: " << gato02->edad << std::endl;

    delete gato;
    delete gato02;
    return 0;
}

void sumaEdad(Cat *&g)
{
    int a = 2;
    g->edad = g->edad + a;
    std::cout << "Nueva edad de juancho: " << g->edad << std::endl;
}
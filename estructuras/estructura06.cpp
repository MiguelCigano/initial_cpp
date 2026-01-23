/*
** Paso de estructura por puntero
*/

#include <iostream>

struct Cat {
    std::string nombre;
    int edad;
};

void sumaEdad(Cat *&g);

int main(int argc, char** argv)
{
    Cat *gato       = new Cat;
    gato->nombre    = "juancho";
    gato->edad      = 10;

    Cat *gato02     = new Cat;
    gato02->nombre  = "benito";
    gato02->edad    = 7;

    // Copiamos los datos de juancho hacia benito 
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


/*
🔹 Solución 2: Pasar un puntero doble a sumaEdad para modificar gato
Si necesitas modificar el puntero dentro de sumaEdad(), pásalo como Cat**:

void sumaEdad(Cat **g) {
    (*g)->edad += 2;
    std::cout << "Nueva edad de juancho: " << (*g)->edad << std::endl;
}

sumaEdad(&gato);
🔹 Esto es útil si quisieras cambiar la dirección de gato dentro de la función.

✔ Usa Cat *g si solo quieres modificar los atributos del objeto al que apunta el puntero.
✔ Usa Cat *&g si quieres cambiar la dirección del puntero (es decir, hacer que apunte a otro objeto).

Si solo estás cambiando propiedades del objeto, no necesitas &.
Si necesitas modificar el puntero en sí, entonces sí necesitas &. 🚀

Cuando pasamos un puntero como argumento a una función sin usar &, lo que se copia es el valor del puntero, es decir, la dirección de memoria que contiene. No se copia el objeto al que apunta el puntero.



*/
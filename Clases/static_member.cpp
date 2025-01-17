#include <iostream>

/*
*   Un  miembro statico es similar a un objeto declarado en un namespace
*   la clase a la que pertenece asume el rol de namespace.
*   En otras palabras hay una sola copia de cada miembro estico sin importar el numero
*   de instancias de la clase.
*   Las clase derivadas tambien comparten esa unica copia.
*/

class filename
{
    public:
        static const int max_lenght = 1024;
        static const char path_separator = '/';
        static filename current_directory;
        filename(const char *str);
    private:
        char name_[max_lenght];
};

const int filename::max_lenght;
const char filename::path_separator;
filename filename::current_directory(".");

filename::filename(const char* str)
{
    strcpy(name_, str, max_lenght-1);
}
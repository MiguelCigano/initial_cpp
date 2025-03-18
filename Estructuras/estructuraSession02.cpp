#include <iostream>

struct Point {
    int x;
    int y;

    void print_values() {
        std::cout << "x:" << x << std::endl;
        std::cout << "y:" << y << std::endl;
    }
};

int main(int argc, char **argv)
{
    Point a = {2, 1};   // inicialización de "a"
    Point b = a;        // COPIA durante la declaración
    b.print_values();   // Uso de función miembro

    Point c = {4, 3};   // inicialización de "c"
    c = b;              // ASIGNACIÓN después de la inicialización

    return 0;
}
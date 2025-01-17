/* Accesando a datos miembros de de un objeto en la memoria HEAP 
usando el operador "points-to operator" (->)*/

#include <iostream>

using namespace std;

class mascotaGato
{
    public:
        mascotaGato()  { suEdad = 10; } // en línea
        ~mascotaGato() {}

        int obteniendoEdad() const { return suEdad; }
        void configurandoEdad(int Edad) { suEdad = Edad; }

    private:
        int suEdad;
};

int main(int argc, char **argv)
{
    mascotaGato *cucho = new mascotaGato;
    cout << "Cucho tiene " << cucho->obteniendoEdad() << " años de edad." << endl;
    cout << "Cambiando la edad de Cucho..." << std::endl;
    cucho->configurandoEdad(13);
    cout << "Ahora Cucho tiene " << cucho->obteniendoEdad() << " años de edad." << endl;

    delete cucho;

    return 0;
}
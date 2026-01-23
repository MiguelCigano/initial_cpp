/* Crando variables miembros en la FreeStore */

#include <iostream>

using namespace std;

class mascotaGato
{
    public:
        mascotaGato();
        ~mascotaGato();
        long int obteniendoEdad() const { return *suEdad; }
        void configurandoEdad(long int Edad) { *suEdad = Edad; }

    private:
        long int *suEdad;
    
};

mascotaGato::mascotaGato()
{
    suEdad = new long int(2);
}

mascotaGato::~mascotaGato()
{
    delete suEdad;
}

int main(int argc, char **argv)
{
    mascotaGato *cucho = new mascotaGato;
    std::cout << "La edad de Cucho es: " << cucho->obteniendoEdad() << " de edad." << std::endl;
    cucho->configurandoEdad(255);
    std::cout << "La edad de Cucho es: " << cucho->obteniendoEdad() << " de edad." << std::endl;

    delete cucho;

    return 0;
}
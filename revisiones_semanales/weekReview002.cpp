#include <iostream>

#define ALTURA 6
#define BASE 6

using namespace std;

enum selector
{
    dibujarTriang = 1,
    reconfigurar,
    salir
};

// definción de la clase triagulo
class Triang
{
    public:
        // constructor y destructor de la clase (declaración)
        Triang(int temporalAltura, int temporalBase);
        ~Triang();

        // accesadores a variables privadas
        int obtenerAltura() const { return altura; } // implementación en línea
        int obtenerBase();                     // implementacion fuer de línea

        // métodos
        void reconfiguraTriang(int nuevaAltura, int nuevaBase);

    private:
        // atributos
        int altura;
        int base;
};

// definición de los métodos públicos
// constructor
Triang::Triang(int temporalAltura, int temporalBase)
{
    altura = temporalAltura;
    base = temporalBase;
}

Triang::~Triang()
{
    // destructor
}

int Triang::obtenerBase()
{
    return base;
}


void Triang::reconfiguraTriang(int nuevaAltura, int nuevaBase)
{
    altura = nuevaAltura;
    base = nuevaBase;
}

// definción de prototipo de funciones que recibe a la clase
void hacerDibujoTriang(Triang);
int funHacerMenu();

int main(void)
{
    Triang miTriangulo(ALTURA, BASE);
    
    int seleccion = dibujarTriang;
    bool iterador =  false;

    while(!iterador)
    {
        seleccion = funHacerMenu();

        if(seleccion < dibujarTriang || seleccion > reconfigurar)
        {
            std::cout << "Error en la selección, vuelve a intentar..." << std::endl;
            iterador = true;
        }
        
        switch (seleccion)
        {

        case dibujarTriang:
            hacerDibujoTriang(miTriangulo);
            break;
        
        case reconfigurar:
            int newAltura;
            int newBase;

            std::cout << "Introduce nueva altura: " << std::endl;
            std::cin >> newAltura;
            std::cout << "\nConsidera que la base será igual a la altura " << std::endl;
            
            newBase = newAltura;

            miTriangulo.reconfiguraTriang(newAltura, newBase);
            hacerDibujoTriang(miTriangulo);
            break;

        case salir:
            iterador = true;
            std::cout << "Saliendo del menu..." << std::endl;
            break;
        
        default:
            iterador = true;
            break;
        }
    }
    return 0;
}

// Definición de funciones

int funHacerMenu()
{
    int seleccion;

    std::cout << std::endl << std::endl;  // crea nuevas lineas
    std::cout << "*** Menu ***" << std::endl;
    std::cout << "(1) Dibujar Triangulo" << std::endl;
    std::cout << "(2) Reconfigurar" << std::endl;
    std::cout << "(3) Salir" << std::endl;
    std::cout << std::endl;
    std::cin >> seleccion;
    std::cout << std::endl;

    return seleccion;
}

void hacerDibujoTriang(Triang miTrian)
{
    int altura = miTrian.obtenerAltura();
    int base = miTrian.obtenerBase();

    int iniAux = 0;
    int finAux = base;
    
    if(altura % 2 == 0)
    {
        for(int i = 0; i < altura; i++)
        {   
            for(int j = 0 ; j < i ; j++)
            {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    else
        std::cout << "Introduce un numero par" << std::endl;
}

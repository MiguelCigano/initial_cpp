#include <iostream>

using namespace std;

enum CHOIC
{
    dibujarRect = 1,
    getArea, 
    getPerim,
    cambioDim,
    qOut
};

// Declaración de la clase rectangulo
class Rtan
{
    public:
        // se define el constructor
        Rtan(int w, int h);
        ~Rtan();                            // destructor

        // accesadores implementados en línea
        int getH() const { return itsH; }
        int getW() const { return itsW; }
        int getArea() const { return itsH * itsW; }
        int getPerim() const { return 2*itsH + 2*itsW; }
        void setSize(int newW, int newH);

    private:
        int itsH;
        int itsW;     
};

// Implementación de los métodos
void Rtan::setSize(int newW, int newH)
{
    itsW = newW;
    itsH = newH;
}

// creo que este es la definción del constructor
Rtan::Rtan(int newW, int newH)
{
    itsW = newW;
    itsH = newH;
}

Rtan::~Rtan()
{
    // destructor
}

//Prototipos de fuciones
// Nota que a todas las funciones se les pasa el objeto clase como argumento
int doMenu();
void doDrawRect(Rtan);
void doGetArea(Rtan);
void doGetPerim(Rtan);

int main(void)
{
    // incializa un rectanguo a 30, 5

    Rtan elRectan(30, 5);
    int choice = dibujarRect;
    int fqOut = false;

    while(!fqOut)
    {
        choice = doMenu();

        // || OR lógica
        if(choice < dibujarRect || choice > qOut)
        {
            std::cout << "\nSelección invalida, intenta de nuevo..." << std::endl;
            continue;
        }

        switch(choice)
        {
            case dibujarRect:
                doDrawRect(elRectan);
                break;

            case getArea:
                doGetArea(elRectan);
                break;
            
            case getPerim:
                doGetPerim(elRectan);
                break;

            case cambioDim:
                int newL;
                int newWidth;

                std::cout << "new Width: "<< std::endl;
                std::cin >> newWidth;
                std::cout << "new Height: ";
                std::cin >> newL;

                elRectan.setSize(newWidth, newL);
                doDrawRect(elRectan);
                break;

            case qOut:
                fqOut = true;
                std::cout << "Saliendo... " << std::endl << std::endl;
                break;
            
            default:
                std::cout << "Error en la elección! " << std::endl;
                fqOut = true;
                break;    
        }   // fin del switch
    }       // fin del while


    return 0;
}           // fin del main


// Definición de funciones

int doMenu()
{
    int choice;

    std::cout << std::endl << std::endl;  // crea nuevas lineas
    std::cout << "*** Menu ***" << std::endl;
    std::cout << "(1) Dibujar Rectangulo" << std::endl;
    std::cout << "(2) Area" << std::endl;
    std::cout << "(3) Perimetro"<< std::endl;
    std::cout << "(4) Resize" << std::endl;
    std::cout << "(5) Salir" << std::endl;

    std::cin >> choice;

    return choice;
}

void doDrawRect(Rtan elRect)
{
    int h = elRect.getH();
    int w = elRect.getW();

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            std::cout << "*";
        }
        std::cout << endl;
    }
}

void doGetArea(Rtan elRect)
{
    std::cout << "Area: " << elRect.getArea() << std::endl;
}

void doGetPerim(Rtan elRect)
{
    std::cout << "Perimetro: " << elRect.getPerim() << std::endl;
}
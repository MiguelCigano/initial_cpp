#include <iostream>

using namespace std;

enum CHOICE
{
    drawRect = 1;
    getArea, 
    getPerim,
    changeDimensions,
    qOut
};

// Declaracion de la clase rectangulo

class Rtan
{
    public:
        // se define el constructor
        Rtan(int w, int h);
        ~Rtan();

        // accesadores
        int getH() const {return itsH; }
        int getW() const {return itsW; }

        

}
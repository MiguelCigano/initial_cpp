#include <iostream>

// Clases oon otras clases como miembros

using namespace std;

// La clase punto es la encargada de sostener los puntos "x" y "y"
class Punto
{
    // por alguna razon no se esta usando el constructor
    public:
        void setX(int x) { itsX = x; }
        void setY(int y);

        int getX() const { return itsX; }
        int getY() const;

    private:
    int itsX;
    int itsY;
};

void Punto::setY(int y)
{
    itsY = y;
}

int Punto::getY() const
{
    return itsY;
}

class Rtan
{
    public:
        Rtan(int top, int left, int bottom, int right); 
        ~Rtan() {} // Destructor
        
        // Las siguientes declaraciones (implementaciones) son en línea
        int getTop() const { return itsTop; }
        int getLeft() const { return itsLeft; }
        int getBottom() const { return itsBottom; }
        int getRight() const { return itsRight; }

        Punto getUpperLeft() const { return itsUpperLeft; }
        Punto getULowerLeft() const { return itsLowerLeft; }
        Punto getUpperRight() const { return itsUpperRight; }
        Punto getLowerRight() const { return itsLowerRight; }

        void setUpperLeft(Punto Location) {itsUpperLeft = Location; }
        void setLowerLeft(Punto Location) { itsLowerLeft = Location; }
        void setUpperRight(Punto Location) {itsUpperRight = Location; }
        void setLowerRight(Punto Location) { itsLowerRight = Location; }

        int getArea() const;

    private:
        
        int itsTop;
        int itsLeft;
        int itsBottom;
        int itsRight;

        Punto itsUpperLeft;
        Punto itsLowerLeft;
        Punto itsUpperRight;
        Punto itsLowerRight;
};


Rtan::Rtan(int top, int left, int bottom, int right)
{
    itsTop = top;
    itsLeft = left;
    itsBottom = bottom;
    itsRight = right;

    itsUpperLeft.setX(left);
    itsUpperLeft.setY(top);

    itsLowerLeft.setX(left);
    itsLowerLeft.setY(bottom);

    itsUpperRight.setX(right);
    itsUpperRight.setY(top);

    itsLowerRight.setX(right);
    itsLowerRight.setY(bottom);
}

// Calcule el area del rectangulo a partir de los puntos

int Rtan::getArea() const
{
    int ancho = itsRight - itsLeft;
    int alto = itsTop - itsBottom;
    int area = ancho * alto;

    return area;
}

int main()
{
    //  inicializa una varibale local llamada del tipo Rtan

    Rtan miRectangulo(100, 20, 50, 80);

    int area = miRectangulo.getArea();

    std::cout << area << std::endl;

    return 0;
}




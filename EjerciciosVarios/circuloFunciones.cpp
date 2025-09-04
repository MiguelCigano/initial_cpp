#include <iostream>
#include <cmath>

using namespace std;
const double _pi = 3.1416;

// Funciones
void area_circulo(const int diametro_){
    double area, radio = diametro_ / 2.0;
    area = _pi * pow(radio, 2);
    cout << "Area: " << area << endl;
    return;
}

void perimetro_circulo(const int d){
    double p;
    p = _pi * d;
    cout << "Perimetro: " << p << endl;
    return;
}

// Función principal
int main(){
    int diametro;
    cout << "Ingresa el diametro del circulo:" << endl;
    cin >> diametro;
    cout << "El diametro es: " << diametro << endl;
    area_circulo(diametro);
    perimetro_circulo(diametro);

    return 0;
}
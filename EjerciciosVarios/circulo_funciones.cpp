#include <iostream>
#include <cmath>

using namespace std;
const double pi_ = 3.1416;

// Prototipos de funciones

int area_circ(int d);
int per_circ(int diametro_);

// Función principal

int main(){

    int diametro_;

    cout << "Ingresa el diametro del circulo: \n";
    cin >> diametro_;
    cout << "El diametro es: \n" << diametro_ << endl;
    area_circ(diametro_);
    per_circ(diametro_);

    return 0;

}

// Zona de funciones

int area_circ(int diametro_){
    int area_;
    area_ = pi_*pow(diametro_/2, 2);
    cout << area_ << endl;
    return 0;
}

int per_circ(int d){
    int p;
    p = pi_*d;
    cout<< p <<endl;
    
    return 0;
}
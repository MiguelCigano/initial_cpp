#include <iostream>
#include <cmath>

using namespace std;
const double pi_ = 3.14166;

double area_circ(double diametro_, double pi_){
    double area_;
    area_ = pi_*pow(diametro_/2, 2);
    cout<<"El area del circulo es: \n" << area_ << endl;
    return area_;
}

double per_circ(double diametro_){
    double perimetro_;
    perimetro_ = pi_*diametro_;
    cout<< "El perimetro del circulo es: \n" << perimetro_ << endl;
    return 0;
}

int main(){
    double diametro_;
    cout << "Ingresa el diametro del circulo: \n";
    cin >> diametro_;
    cout << "El diametro del circulo es: \n" << diametro_ << endl;

    area_circ(diametro_, pi_);
    per_circ(diametro_);

    return 0;
}


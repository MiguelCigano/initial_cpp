#include <iostream>
using namespace std;
//programa pasa el vector como valor

//esta función pasa los valores de un vector como valor a una función en la que se vacian a otro vector
int pasar_vec(int myvec_valor[], int myvec_valor_2[], int tam);
double promedio_vec(int myvec_valor[], int myvec_valor2[], int tam);

int main(){
    int tam = 7;
    int myvec_valor[7] = {20, 1, 1, 1, 1, 1, 10};
    int myvec_valor_2[7] = {0};
    pasar_vec(myvec_valor, myvec_valor_2, tam);
    promedio_vec(myvec_valor, myvec_valor_2, tam);
    return 0;
}

int pasar_vec(int myvec_valor[], int myvec_valor_2[], int tam){   
    for (int j = 0; j<tam; j++){
        myvec_valor_2[j] = myvec_valor[j];
    }
    for (int j = 0; j<7; j++){
        cout << myvec_valor_2[j] << " ";
    } 
    cout << endl;
    return 0;
}

double promedio_vec(int myvec_valor[], int myvec_valor_2[], int tam){
    double sum = 0;
    double prome = 0;
    for(int j = 0; j<7; j++ ){
        sum += myvec_valor[j];
    }
    prome = sum/tam;
    cout << "suma: " << sum << endl;
    cout << "promedio: " << prome << endl; 
    return 0;
}

// Si pasas el vector como valor, obtienes a la salilda el vector es: 0x7fffffffdb5c, por lo que solo estás obteniendo la dirección.

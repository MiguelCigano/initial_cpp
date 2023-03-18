#include <iostream>
using namespace std;

int promedio_vec(unsigned char* myvec_valor[3]);

int main(){
    unsigned char myvec_valor[3] = {1, 1, 3};
    promedio_vec(myvec_valor);
    return 0;
}

int promedio_vec(unsigned char* myvec_valor[3]){
    cout << "el vector es: " << *myvec_valor << endl;
    return 0;
}

// Si pasas el vector como valor, obtienes a la salilda el vector es: 0x7fffffffdb5c, por lo que solo estás obteniendo la dirección.
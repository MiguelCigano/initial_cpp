#include <iostream>

using namespace std;

int main(){
    int *i_pointer; // se declara un puntero llamado i_pointer como un tipo entero
    int a, b;
    a = 22;
    int *pa;
    int *pb = &b;
    int i; // se declara una variable i del tipo entero
    i_pointer = &i; // se asigna la dirección de i a el punteoro i_pointer
    i = 10;  //inicializamos la variable de tipo entero
    cout<<"Salida i tipo entero = "<< i <<endl;
    cout<<"Salida de puntero tipo entero = "<<*i_pointer<<endl;
    pa = &a;
    cout<<"el puntero *pa : "<<*pa<<endl;
    cout<<"el puntero pa : "<<pa<<endl;
    cout<<"el puntero pb : "<<*pb<<endl;
}

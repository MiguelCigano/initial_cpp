#include <iostream>
#include <string>

using namespace std;

int main(){
    int *n = new int; // este apuntador esta accediento a una variable entera en el HEAP
    *n = 18;
    cout << sizeof(*n) << endl;
    cout << sizeof(n) << endl;

    char *c = new char; // espacio apuntado
    *c = 'x';  // letra que se guardara en el espacio apuntado -- "char" ocupa un  byte
    cout << sizeof(*c) << endl;
    cout << sizeof(c) << endl;

    /*todos los punteros ocupan 8 bytes independientmente del tamaño de la variable en el STACK*/
    cout << c << endl;

}
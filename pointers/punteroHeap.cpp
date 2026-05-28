#include <iostream>
#include <string>

typedef int valor;


using namespace std;

int main(){
    
    // srand(time(NULL));
    // short aleat = 1 + rand()%5;

    uint16_t x;
    x = 400;

    uint16_t *ptr;
    ptr = &x;

    std::cout << "el valor que almaneca ptr es:" << *ptr << std::endl;
    std::cout << "la dirección que almacena ptr es:" << ptr << std::endl;
    std::cout << "la dirección de ptr es:" << &ptr << std::endl;
    std::cout << "la dirección de x es:" << &x << std::endl;          

    valor i2, i3, i4;
    char *c = new char; // espacio apuntado

    *c = 'M';  // letra que se guardara en el espacio apuntado -- "char" ocupa un  byte


    // /*todos los punteros ocupan 8 bytes independientmente del tamaño de la variable en el STACK*/
    // cout << c << endl;
    // int i = 5;
    // cout << sizeof(i) << endl;

    // int *p = &i;


}
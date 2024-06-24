#include <iostream>

 /* una función que copie un arreglo hacia otro arreglo */

 using namespace std;

struct MyStruct 
{
    int x;
    float y;
};

/* prototipo de interfaz */
/* Esta función debe copiar */

void arrayCopy(unsigned char *arrayA, unsigned char *arrayB, unsigned char size);

 int main()
 {
    int aa = 11;
    float bb = (float)aa / 5;
    std::cout << bb << std::endl;


    int numero = 1;
    int *pNumeroFinal = &numero;
    int *numeroDouble = reinterpret_cast<int*>(pNumeroFinal);
    std::cout << *numeroDouble << std::endl;


    MyStruct s = { 42, 3.14f };
    // Convertir un puntero a MyStruct en un puntero a char
    char* pBytes = reinterpret_cast<char*>(&s);

    // Imprimir los bytes individuales del struct
    for (size_t i = 0; i < sizeof(MyStruct); ++i) {
        std::cout << static_cast<int>(pBytes[i]) << " ";
    }
    std::cout << std::endl;


    return 0;
 }
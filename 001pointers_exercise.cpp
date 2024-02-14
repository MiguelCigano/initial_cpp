/*------------------------------------------
Parte VI: Punteros

Las siguuientes funciones son algunas de las más comunes de los algoritmos  que puedes hacer en C y son una buena excusa para practicar punteros. Por lo tanto la mayoria de ellos son preguntas de entrevista.

------------------------------------------ */

// 1. Realiza una función que calcule el promedio de los valores de un array

#include <iostream>
//#include <iomanip>
#include <cstdio>

unsigned char avrg(unsigned char *arr, unsigned char *size_);

int main(){
    unsigned char arr[5] = { 1, 2, 3, 4, 7};
    unsigned char size_ = sizeof(arr)/sizeof(*arr);
    unsigned char prm = avrg(arr, &size_);
    //avrg(arr, &size_);
    //std::cout<<"El promedio es: "<<prm<<std::endl;
    // std::cout << "Número char: " << std::fixed << std::setprecision(2) << static_cast<float>(prm) << std::endl;
    double valor = static_cast<double>(prm);
    std::cout<< "valor es: " << valor<<std::endl;
}

unsigned char avrg(unsigned char *arr, unsigned char *size_ptr){
    float suma = 0;
    std::cout<<"Arreglo char es: "<< *size_ptr <<std::endl;

    int sz_int = static_cast<int>(*size_ptr);
    int arr_int[sz_int]; 

    for (int i=0; i<sz_int; i++){
        arr_int[i] = static_cast<int>(arr[i]);      
    }
    for (int i=0; i<sz_int; i++){
        std::cout<<arr_int[i]<<" ";      
    }
    for (int i=0; i<sz_int; i++){
        suma = suma + arr_int[i];
    }
    std::cout<<std::endl;

    //unsigned char prm;
    
    std::cout<<suma/sz_int<<std::endl;

    return suma/sz_int;
}

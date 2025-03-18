#include <iostream>

void intercambio(int *x, int *y){
    int temporal;
    temporal = *x;
    *x = *y;
    *y = temporal;
}

int main(int argc, char *argv[]) 
{
    int a = 10, b = 20;     
    intercambio(&a, &b);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
} 

// int main(int argc, char *argv[])
// {
//     int array_b[] = {10, 20, 30, 40, 50};
//     int *ptr1 = array_b;       // dirección del array b
//     int *ptr2 = &array_b[0];   // dirección del primer elemento del array b
// }


// #define SIZE 5

// int main(int argc, char *argv[])
// {
//     int x, y, return 0;          // inicializacion
//     y = 20;

//     int *ptr1;          // declaracion
//     ptr1 = &x;          // inicializacion

//     int *ptr2;          // INCORRECTO
//     ptr2 = &y;
// }


#include <iostream>
/* una función que retorna el valor más grade de un arreglo */

unsigned short largest(unsigned short *array, unsigned char size);

int main(void)
{   
    unsigned short array[5] = {9000, 200, 300, 40, 5000};
    int size = sizeof(array) / sizeof(array[0]);

    unsigned short valGrande = largest(array, size);
    std::cout << "Valor más grande es: " << valGrande << std::endl;
    std::cout << std::endl;

    return 0;
}

unsigned short largest(unsigned short *array, unsigned char size)
{
    int valGrande = array[0];

    for(int i = 1; i < size; i++)
    {
        if(array[i] > valGrande)
        {   
            valGrande = array[i];
        }
        
    }

    return valGrande;
}

#include <iostream>

 /* una función que copie un arreglo hacia otro arreglo */

 using namespace std;


/* prototipo de interfaz */
/* Esta función debe copiar */

void arrayCopy(unsigned char *arrayA, unsigned char *arrayB, unsigned char size);

/* la función dee copiar el contenido de un arreglo en el otro de tal manera que despues del llamd de la funcioón, ambos arreglos tengan los mismos elementos*/

 int main()
 {
    unsigned char arrayA[5] = {'a', 'b', 'c', 'd', 'f'};
    unsigned char size = sizeof(arrayA)/sizeof(arrayA[0]);
    unsigned char arrayB[5] = {'1', '2', '3', '4', '5'};

    std::cout << "Antes del llamado de función: " << std::endl;

    for(int i = 0; i<size; i++)
    {
        std::cout<< arrayA[i] << " ";
    }

    std::cout << std::endl;    
    std::cout << "------------------" << std::endl;

    for(int i = 0; i<size; i++)
    {
        std::cout<< arrayB[i] << " ";
    }
    std::cout << std::endl;    

    /* llamado de función */
    arrayCopy(arrayA, arrayB, size);

    std::cout << std::endl;
    std::cout << "Después del llamado de función: " << std::endl;
    
    for(int i = 0; i<size; i++)
    {
        std::cout<< arrayA[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "------------------" << std::endl;

    for(int i = 0; i<size; i++)
    {
        std::cout<< arrayB[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
 }

 void arrayCopy(unsigned char *arrayA, unsigned char *arrayB, unsigned char size)
 {
    for(int i; i<size; i++)
    {
        arrayB[i] = arrayA[i];
    }
 }
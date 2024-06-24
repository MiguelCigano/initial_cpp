#include<iostream>

void printArray1(int (*ptr) [4]);
void printArray2(int (*ptr) [4], int n);
void printMatrix(int (*ptr) [4], int n);

int main()
{
    int multi[3][4] = { {1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}
                      };

    int (*ptr)[4];
    int count;

    ptr = multi;

    /* En cada ciclo, ptr es incrementado al siguiente elemento de multi */
    /* es decir, el siguiente  arreglo de enteros de 4 elementos */

    for(count = 0; count < 3; count++)
    {
        printArray1(ptr++);
    }

    std::cout << "\nSegunda función... " << std::endl;

    printArray2(multi, 3);

    std::cout << "\nTercera función... " << std::endl;

    printMatrix(multi, 3);
}

void printArray1(int (*ptr)[4])
{
    /* imprime los elementos de un solo arreglo entero de 4 elementos */
    /* p es un puntero a un tipo int. Se debe usar un modificador de tipo para hacer que */
    /* p sea igual a la dirección de ptr */

    int *p;
    int count;
    // Cast de estilo C para convertir el puntero int* a un puntero int*
    p = (int *)ptr;

    for(count = 0; count < 4; count++)
    {
        //std::cout << *ptr++;
        std::cout << *ptr++ << " ";
    }
    std::cout << std::endl;
}

void printArray2(int (*ptr)[4], int n)
{
    int *p;
    int count;

    p = (int *)ptr;

    for(count = 0; count < 4; count++)
    {
        std::cout << *p++ << " " << std::endl;
    }
    std::cout << std::endl;
}

void printMatrix(int (*ptr)[4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++){
            std::cout << ptr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
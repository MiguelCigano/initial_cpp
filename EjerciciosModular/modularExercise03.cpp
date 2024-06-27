#include <iostream>

using namespace std;

unsigned char arrayCompare(unsigned char *arrayA, unsigned char *arrayB, unsigned char size);

int main()
{
    unsigned char arrayA[5] = {'a', 'b', 'c', 'd', 'f'};
    unsigned char size = sizeof(arrayA)/sizeof(arrayA[0]);
    unsigned char arrayB[5] = {'a', 'b', 'c', 'd', 'f'};

    unsigned char resultado;

    resultado = arrayCompare(arrayA, arrayB, size);
    int resultado_int = static_cast<int>(resultado);

    std::cout << resultado << std::endl;

    return 0;    
}

unsigned char arrayCompare(unsigned char *arrayA, unsigned char *arrayB, unsigned char size)
{
    int i = 0;

    while(i<size)
    {
        if(i == (size - 1))
        {
            if(arrayA[i] == arrayB[i])
            {
                std::cout << "Son iguales, valor retornado es: " << std::endl;
                break;
            }
        }

        if(arrayA[i] != arrayB[i])
        {
            std::cout << "Son diferentes, valor retornado es: " << std::endl;
            return '1';
            break;
        }

        i++;
    }

    return '0';
}
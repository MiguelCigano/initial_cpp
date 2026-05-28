#include <iostream>

/* Asignacion de valor incial a un arreglo de punteros a tipo char*/

int main()
{
    char *message[4] = { "Hola ", "no ", "la ", "cagues"};

    for(int i = 0; i<4; i++)
    {
        // std::cout << "%s" << message[i] << std::endl;
        printf("%s", message[i]);
    }
    std::cout << std::endl;
}
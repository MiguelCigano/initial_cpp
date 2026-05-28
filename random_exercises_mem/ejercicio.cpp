#include <iostream>
#include <cstring>  // Biblioteca necesaria para strcpy y strlen

int main() {
    const char *origen = "Hola, mundo!";
    char destino[20];

    // Copiamos la cadena de origen a destino
    strcpy(destino, origen);

    // Obtenemos la longitud de la cadena de origen
    size_t longitud = strlen(origen);

    // Imprimimos los resultados
    std::cout << "Destino: " << destino << std::endl;
    std::cout << "Longitud: " << longitud << std::endl;

    // Usamos std::getline en lugar de gets
    char input[50];
    std::cout << "Introduce una cadena: ";
    std::cin.getline(input, sizeof(input));
    std::cout << "Has introducido: " << input << std::endl;

    return 0;
}
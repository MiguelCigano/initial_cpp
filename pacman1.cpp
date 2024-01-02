#include <iostream>
// #include <conio.h>  // Para _getch()

using namespace std;

const int anchoLaberinto = 10;
const int altoLaberinto = 5;

char laberinto[altoLaberinto][anchoLaberinto] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'P', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int posX = 1;
int posY = 1;

void dibujarLaberinto() {
    for (int i = 0; i < altoLaberinto; ++i) {
        for (int j = 0; j < anchoLaberinto; ++j) {
            cout << laberinto[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    char input;

    do {
        system("cls");  // Limpiar la consola
        dibujarLaberinto();

        //input = _getch();  // Obtener entrada del usuario sin necesidad de presionar Enter
        cin.get();

        // Actualizar posición del jugador
        switch (input) {
            case 'w': // Arriba
                if (laberinto[posY - 1][posX] != '#') {
                    laberinto[posY][posX] = '.';
                    posY--;
                }
                break;
            case 's': // Abajo
                if (laberinto[posY + 1][posX] != '#') {
                    laberinto[posY][posX] = '.';
                    posY++;
                }
                break;
            case 'a': // Izquierda
                if (laberinto[posY][posX - 1] != '#') {
                    laberinto[posY][posX] = '.';
                    posX--;
                }
                break;
            case 'd': // Derecha
                if (laberinto[posY][posX + 1] != '#') {
                    laberinto[posY][posX] = '.';
                    posX++;
                }
                break;
        }

    } while (input != 'q');  // Salir del juego al presionar 'q'

    return 0;
}
#include <iostream>
#include <string>
#include <time.h>

#define MAX 32 // se define una contante simbolica a través de la directiva #define

using namespace std;

// definción de prototipos

void mensaje();
int choose_level();
int choose_row(int level);
int choose_columns(int level);
int choose_n_minas(int level);
void inicializaTablero(int row, int col, char space[MAX][MAX]);
void colocaMinas(int row, int col, char space2[MAX][MAX], int minas);
void colocaNum(int row, int col, char space[MAX][MAX]);
void imprimirJugada(int row, int col, char space[MAX][MAX], char space2[MAX][MAX], short f2, short c2);

int main(){

    int level, row, col, min, f2, c2;
    short turno = 0;
    char space[MAX][MAX]; /*esta matriz tiene solo ceros*/
    char space2[MAX][MAX]; // esta matriz contiene las minas y los ceros

    mensaje();
    level = choose_level();
    row = choose_row(level);
    col = choose_columns(level);
    min = choose_n_minas(level);

    inicializaTablero(row, col, space);
    colocaMinas(row, col, space2, min);

    std::cout << std::endl;

    // el siguien for solo es para mostrar donde están las minas, se le hara una función más adelante de mostrar solución.
    // for (int i = 1; i<row+1; i++){
    //     for (int j = 1; j < col+1; j++){
    //         cout << space2[i][j];
    //     }
    //     cout << endl; // pasar a la siguiente fila
    // }

    colocaNum(row, col, space2);
    cout << endl;
    
    // for (int i = 1; i<row+1; i++){
    //     for (int j = 1; j < col+1; j++){
    //         cout << space2[i][j];
    //     }
    //     cout << endl;
    // }

    while(1){

        std::cout<<"tell me what row and column"<< std::endl;
        std::cin >> f2 >> c2;
        std::cout<<std::endl;
        
        if(f2>0 & f2<=row){
            std::cout<<"row selected is: "<< f2 << std::endl;
            turno++;
        }
        else std::cout<<"fila incorrecta"<< std::endl;
        
        if(c2>0 & c2<=col){ 
            std::cout<<"column selected: "<< c2 << std::endl;
            turno++;        
        }
        else std::cout<<"column incorrect"<< std::endl;

        imprimirJugada(row, col, space, space2, f2, c2);
        std::cout<<std::endl;
        
        if(turno==(3)*2) break;

    }    
}


// functions definition-------------------------------

void mensaje () {

    cout<< "Welcome to Buscaminas"<< endl;
    cout<< "The levels are:" << endl;
    cout<< "Level 1: Templario"<< endl;
    cout<< "Level 2: D-day"<< endl;
    cout<< "Level 3: Suicidio"<< endl;

}

int choose_level(){

    int l;
    while(1) {
        cout<< "Introduce the choosed level: ";
        cin >> l;
        if (l==1) break;
        else if (l == 2) break;
        else if (l == 3) break;
    }
    return l;

}

int choose_row(int level){

    int r;
    if (level == 1) r == 8;
    else if (level == 2) r == 16;
    else if (level == 3){
        while(1) {
            cout << "Are you ready? Come on, tell me how do you want died? (insert rows): ";
            cin >> r;
            if(r <= 30) break;
        }
    }
    return r;

}

int choose_columns(int level){

    int c;
    if (level == 1) c == 8;
    else if (level == 2) c == 16;
    else if (level == 3){
        while(1) {
            cout << "number of columns: ";
            cin >> c;
            if (c <=30) break;
        }
    }
    return c;

}

int choose_n_minas(int level){
    int m;
    if (level == 1) m == 10;
    else if (level == 2) m == 12;
    else if (level == 3){
        while(1) {
            cout << "number of minas: ";
            cin >> m;
            if (m <= 15) break;
            else {
                std::cout << "these number of mines is imposible" << std::endl;
            }
        }
    }
    return m; 
}

void inicializaTablero(int row, int col, char space[MAX][MAX]){

    for(int i = 0; i<row+2; i++ ){
        for(int j = 0; j<col+2; j++){
            space[i][j] = '0'; /*Recuerda que space almacena chars*/
            if(i==0) space[i][j] = '-';
            if(i==row+1) space[i][j] = '-';
            if(j==0) space[i][j] = ':';
            if(j==col+1) space[i][j] = ':';
        }
    }

    cout << endl << "The table has been created, You can start to play!" << endl;
    cout << "The currently table is:" << endl << endl;
    
    // el siguiente for muestra el tablero en ceros
    for(int i = 0; i<row+2; i++){
        for(int j = 0; j<col+2; j++){
            cout << space[i][j];
        }
        cout << endl; 
    }


}

void colocaMinas(int row, int col, char space[MAX][MAX], int minas){
    
    int pcol, pfil; // se guardan un numero de fila y columna aleatorio

    for (int i=0; i<row+2; i++){
        for (int j=0; j<col+2; j++){
            space[i][j] = '0';
        }
    }

    srand(time(NULL)); // inicio de la función time para obtener un numero aleatorio
    
    while(1){
        pfil = 1 + rand()%row;
        pcol = 1 + rand()%col;
        if(space[pfil][pcol] == '0'){ // si la posición del espacio es igual al caracter 0, se coloca una mina
            space[pfil][pcol] = '*';
            minas--;
        }
        if (minas == 0) break;
    }
}

// la función coloca numeros tiene la finalidad de indicar cuantas minas hay alrededor de cada casilla
void colocaNum(int row, int col, char space2[MAX][MAX]){
    int num; // guarda la cantidad de minas que hay en la casillas vecina a la casilla en la posición actual
    for (int i=1; i<row+1; i++){
        for (int j=1; j<col+1; j++){
            if (space2[i][j] == '0'){

                num = 0;
                
                if (space2[i-1][j-1] == '*')num++;
                if (space2[i-1][j] == '*')num++;
                if (space2[i-1][j+1] == '*')num++;
                if (space2[i][j-1] == '*')num++;
                if (space2[i][j+1] == '*')num++;
                if (space2[i+1][j-1] == '*')num++;
                if (space2[i+1][j] == '*')num++;
                if (space2[i+1][j+1] == '*')num++;

                if (num == 0) space2[i][j] = ' ';
                else space2[i][j] = num + '0'; // ! la matriz space2 no puede recibir valores enteros, por eso el '0'

                
            }
        } 
    }

}

void imprimirJugada(int row, int col, char space[MAX][MAX], char space2[MAX][MAX], short f2, short c2){

    for(int i=0; i<row+2; i++){
        for(int j=0; j<col+2; j++){
            if (i == f2){
                if (j == c2) space[i][j] = space2[i][j];
             }
             std:cout<<space[i][j];    
            
        }
        cout << endl;
    }

}

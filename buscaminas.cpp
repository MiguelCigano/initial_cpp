#include <iostream>
#include <string>

#define MAX 32

using namespace std;

// Prototypes
void mensaje();
int choose_level();
int choose_row(int level);
int choose_columns(int level);
int choose_n_minas(int level);
void inicializaTablero(int row, int col, char space[MAX][MAX]);

int main() {
    int level, row, col, min;
    char space[MAX][MAX]; /*esta matriz tiene solo ceros*/
    char space2[MAX][MAX];
    mensaje();
    level = choose_level();
    row = choose_row(level);
    col = choose_columns(level);
    min = choose_n_minas(level);
    inicializaTablero(row, col, space);

}

void mensaje () {
    cout<< "Welcomen to Buscaminas"<< endl;
    cout<< "The levels are:" << endl;
    cout<< "Level 1: Noob"<< endl;
    cout<< "Level 2: Blood's Brothers"<< endl;
    cout<< "Level 3: Suicidio"<< endl;        
}

// Definitions
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
        }
    }
    return m; 
}

void inicializaTablero(int row, int col, char space[MAX][MAX]){
    for(int i = 0; i<row+2; i++ ){
        for(int j = 0; j<col+2; j++){
            space[i][j] = '0'; /*Recuerda que space almacena chars*/
        }
    }
    cout << endl << "The table has been created, You can start to play!" << endl;
    cout << "The currently table is:" << endl << endl;
    for(int i = 1; i<row+1; i++){
        for(int j = 1; j<col+1; j++){
            cout << space[i][j];
        }
        cout << endl;
    }

}
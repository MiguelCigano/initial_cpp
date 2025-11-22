#include <iostream>

// Análisis: compara la entrada de dos números, "x" y "y", lo que resulta en tres posibilidades, "x"<"y", "x">"y" y "x"="y".

// el operador "!=" es un operador de comparación, el cual indica que el miembro de la izquierda es diferente al miembro de la derecha.

using namespace std;

int main(){

    srand(time(NULL));
    int aleat = rand();

    int x, y;
    cout<<"Introduce dos números, el primero como x y el segundo como y"<<endl;
    cin>>x>>y;
    if(x!=y){
        if(x<y){
            cout<<"x es menor que y"<<endl;
        }
        else{
                cout<<"x es mayor que y"<<endl;
        }
    }
    else{
        cout<<"x es igual a y"<<endl;
    }

    std::cout << aleat << endl;
}
#include <iostream>
using namespace std;


/*This code have a problem with the "coredump", its a problem with the segmentation of the "arreglo", consider check then*/
/*The possible solution can be the declaration of the array*/

int main()
{
    int arreglo[5], guardar;
    for (int i = 0; i < 5; i++){
        cout << "Ingrese un número: " ;
        cin >> arreglo[i];
    }


    for (int i = 0; i < 4; i++){
        for (int j = 0; i < 4; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                guardar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = guardar;
            }
        }  
    }

    for (int i = 0; i < 5; i++){
        cout << arreglo[i]<<endl;
    }

}




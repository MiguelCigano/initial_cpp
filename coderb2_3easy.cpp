#include <iostream>

int EnemigoCercano(int arr[], int longuitud){
    int x = 0;
    int i = 0;
    int y = 0;
    int k;
    int z = 0;
    int j;
    int posd;
    int posi;

    while(i < longuitud and x == 0){
        if(arr[i]==1){
        std::cout << "El jugador se encuentra en la posición: "<< i << std::endl;    
        x = -1;
        }
        i= i + 1;
    }

    k = i - 1;
    j = i - 1;

    while(k<=longuitud && y == 0){
        if(arr[k]==2){
            std::cout << "Un enemigo se encuentra en la posición " << k << " --->" << std::endl;
            posd = k - i;
            y = -1;
        }
        if(k == longuitud and (arr[k] != 2 and arr[k] != 1)){
            std::cout << "No hay enemigos a la derecha" << std::endl;
        }
        k = k + 1;
    }

    while(j>=0 and z == 0){
        //std::cout << "paso " << j << std::endl;
        if(arr[j] == 2){
            std::cout << "Un enemigo se encuentra en la posición " << j << " <---" << std::endl;
            posi = i - j;
            z = 1;
        }
        if(j == 0 and (arr[j] != 2 and arr[j] != 1)){
            std::cout << "No hay enemigos hacia la izquierda" << std::endl;
        }
        
        j = j - 1;
    }


    return 0;
}


int main(){

    int arr[5] = {2, 0, 1, 2, 0};
    int longuitud = sizeof(arr) / sizeof(*arr); 
    std::cout << ":::::::::::: Enemigo más cercano play ::::::::::::" << std::endl;
    //std::cout << "El tamaño del arreglo es de: " << longuitud << std::endl;
    EnemigoCercano(arr, longuitud);
    return 0;
}
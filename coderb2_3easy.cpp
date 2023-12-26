#include <iostream>

int EnemigoCercano(uint16_t arr[], uint16_t longuitud){

    uint16_t x = 0, i = 0, y = 0, z = 0;
    uint16_t k;
    uint16_t j;
    uint16_t posd;
    uint16_t posi;

    while(i < longuitud and x == 0){
        if(arr[i]==1){
        std::cout << "El jugador se encuentra en la posición: "<< i << std::endl;    
        x = -1;
        }
        i= i + 1;
    }

    k = i - 1;
    j = i - 1;

    while(k<=longuitud and y == 0){
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
        if(arr[j] == 2){
            std::cout << "Un enemigo se encuentra en la posición " << j << " <--- \n" << std::endl;
            posi = (i-1) - j;
            z = 1;
            // sección de comparación
            if(posi<posd) std::cout << "Enemigo más cercano a " << posi << " posiciones a la izquierda\n" << std::endl;
            if(posd<posi) std::cout << "Enemigo más cercano a " << posd << "posiciones a la derecha\n" << std::endl;
            if(posi==posd) std::cout << "Enemigo más cercano a " << posi << "posiciones a cualquier lado\n" << std::endl;
        }
        if(j == 0 and (arr[j] != 2 and arr[j] != 1)){
            std::cout << "No hay enemigos hacia la izquierda \n" << std::endl;
        }
        
        j = j - 1;
    }

    return 0;
}

int main(){

    uint16_t arr[11] = {0, 2, 0, 2, 1, 0, 0, 0, 0, 2, 0};
    uint16_t longuitud = sizeof(arr) / sizeof(*arr); 

    std::cout << ":::::::::::: Enemigo más cercano play :::::::::::: \n" << std::endl;
    /*std::cout << "El tamaño del arreglo es de: " << longuitud << std::endl;*/
    EnemigoCercano(arr, longuitud);
    return 0;
}
#include <iostream>

int EnemigoCercano(uint16_t arr[], uint16_t longuitud){

    uint16_t x = 0, i = 0, y = 0, z = 0;
    uint16_t k;
    uint16_t j;
    uint16_t posd;
    uint16_t posi;

   // Para encontrar la posición del jugador 
    while(i < longuitud and x == 0){
        if(arr[i]==1){
            std::cout << "El jugador se encuentra en la posición: "<< i << std::endl;    
        x = -1;
        }
        i= i + 1;
    }

    k = i - 1;
    j = i - 1;

    // Sección para recorrer hacia la derecha y encontrar la posición "k" del arreglo en la que se encuentra el primer enemigo,
    // así como el número de posiciones (posd) necesarias para alcanzarlo.
    while(k<=longuitud and y == 0){
        if(arr[k]==2){
            std::cout << "Un enemigo se encuentra en la posición: " << k << " --->" << std::endl;
            posd = (k+1)-i;
            
            y = -1;
        }
        if(k == longuitud and (arr[k] != 2 and arr[k] != 1)){
            // Esta condición solo se cumple en caso de que no haya enemigos hacia derecha
            // asignamos un valor grande a posd debido a que no hay enemigo por alcanzar
            posd = 1000;

            std::cout << "No hay enemigos a la derecha" << std::endl;
        }

        k = k + 1;
    }


    // Sección para recorrer hacia la izquierda y encontrar la posición "j" del arreglo en la que se encuentra el primer enemigo,
    // así como el número de posiciones (posi) necesarias para alcanzarlo.
    while(j>=0 and z == 0){
        if(arr[j] == 2){

            // Esta condición solo se cumple en caso de que haya enemigos hacia la izquierda
            std::cout << "Un enemigo se encuentra en la posición: " << j << " <--- \n" << std::endl;
            posi = (i-1) - j;
            z = -1;
            
            // Sección de comparación cuando hay enemigos en ambos lados
            if(posd==0 or posi!=0){
                if(posi<posd) std::cout << "Enemigo más cercano aa " << posi << " posiciones a la izquierda\n" << std::endl;
                if(posi<posd) return posi;
                if(posd<posi) std::cout << "Enemigo más cercano aa " << posd << " posiciones a la derecha\n" << std::endl;
                if(posd<posi) return posd;
                if(posi==posd) std::cout << "Enemigo más cercano aa " << posi << " posiciones a cualquier lado\n" << std::endl;
                if(posi==posd) return posd;
            }

            if(posd==0){
                std::cout << "Enemigo más cercano aa " << posi << " posiciones a la izquierda\n" << std::endl;
                return posi;
            }

        }

        if(j == 0 and (arr[j] != 2 or arr[j] == 1)){
            posi = 1000;
            std::cout << "No hay enemigos hacia la izquierda \n" << std::endl;
            
            // Sección de comparación cuando no hay enemigos hacia la izquierda
            if(posd!=0 or posi==0){
                if(posi<posd) std::cout << "Enemigo más cercano a " << posi << " posiciones a la izquierda\n" << std::endl;
                if(posi<posd) return posi;
                if(posd<posi) std::cout << "Enemigo más cercano a " << posd << " posiciones a la derecha\n" << std::endl;
                if(posd<posi) return posd;
                if(posi==posd) std::cout << "Enemigo más cercano a " << posi << " posiciones a cualquier lado\n" << std::endl;
                if(posi==posd) return posi;
            }
            
            if(posd==0){
                std::cout << "Enemigo más cercano a " << posi << " posiciones a la izquierda\n" << std::endl;
                return posi;
            }
            
            if(posi==0){
                std::cout << "Enemigo más cercano a " << posd << " posiciones a la izquierda\n" << std::endl;
                return posd;
            }

        }
        
        j = j - 1;
    }

    return 0;
}

int main(){

    uint16_t arr[7] = {0, 0, 1, 0, 0, 0, 0};
    uint16_t longuitud = sizeof(arr) / sizeof(*arr); 

    std::cout << ":::::::::::: Enemigo más cercano play :::::::::::: \n" << std::endl;
    int salida = EnemigoCercano(arr, longuitud);
    std::cout << "SALIDA: " << salida <<std::endl;
    std::cout << std::endl;
    return 0;
}
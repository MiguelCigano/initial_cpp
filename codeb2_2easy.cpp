#include <iostream>

int EnemigoCercano(int arr[], int longuitud){
    int x = 0;
    int i = 0;
    int salida;
    while(i<longuitud && x!=-1){
        if(arr[i]==1){
            std::cout << "Posición de jugador: " << i << std::endl;
            x = -1;
        
        
        int k = i;
        int y = 0;
        int posd;
        
        while(k<longuitud && y!=-1){
            if(arr[k] == 2){
                y = -1;
                posd = k-i;
                std::cout << "Enemigo a " << posd << " posiciones a la derecha"<< std::endl;
            }
            k++;
        }

        int j = i;
        int z = 0;
        int posi;

        while(j>=0 && z!=-1){
            if(arr[j] == 2){
                z = -1;
                posi = i -j;
                std::cout << "Enemigo a " << posi << " posiciones a la izquierda"<< std::endl;
                if(posd>posi){
                    salida = posi;
                    return salida;
                }
                if(posi>posd){
                    salida = posd;
                    return salida;
                }
                if(posi==posd){
                    salida = posd;
                    return salida;
                }
            }
            j--;   
        }
        }
        i++;
    }
    return salida;
}


int main(){

    int arr[6] = {0, 1, 0, 2, 0, 0}; // se puede cambiar este agreglo!
    int longuitud = sizeof(arr) / sizeof(*arr);
    int s = EnemigoCercano(arr, longuitud);
    std::cout << "Enemigo más cercano a " << s << " posiciones"<< std::endl;

    return 0;
}
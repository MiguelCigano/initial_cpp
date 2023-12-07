#include <iostream>
#include <string>

using namespace std;

int EnemigoCercano(int arr[], int longuitud){
    int x;
    int i = 0; 
    while(i<longuitud && x != -1){
        if(arr[i] == 1){
            x = -1;
            std::cout << "Posicion de jugador: " << i << std::endl;

            //busqueda a la derecha
            int k, j = i;
            int y =0, w, posd, u;

            while(k<20){
                
                if(arr[k] == 0){
                    k=200;
                    std::cout << "Enemigo esta a: " << w << " posiciones a la derechass " << std::endl;
                }
                k++;
            }
            //busqueda a la izquierda
        
            while(j>=0  &&  u!=-1){
                
                if(arr[j] == 2){
                    u = -1;  
                    int posi = i-j;
                    std::cout << "Enemigo esta a: " << posi << " posiciones a la izquoa. " << std::endl;
                }
                j--;
            }

        }

        i++;
        
    }
return 0;
}


int main(){
    int arr[7] = {0, 1, 0, 0, 2, 0, 0};
    int longuitud = sizeof(arr)/sizeof(*arr);

    EnemigoCercano(arr, longuitud);
    return 0;
}
/* 
Using pointers, determine which numbers of an array are even or odd.
*/

#include <iostream>

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *puntero1;
    puntero1 = arr;

    for(int i = 0; i < 10; i++){
        if(arr[i]%2 == 0){
            std::cout << *puntero1++ << " es número par" << std::endl;
        }
        else std::cout << *puntero1++ << " es número impar" << std::endl;
        
    }


    return 0;
}
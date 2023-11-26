#include <iostream>

#define MAX_G 5
#define estudiantes 10

int califi[estudiantes];

int idx;
int total = 0;

int main(void){
    for(idx=0; idx<1*estudiantes; idx++){
        std::cout << "Ingresa el grado de la persona " << idx+1 <<":"<< std::endl;
        std::cin >> califi[idx];

        while(califi[idx]>MAX_G){
            std::cout << "ingresa la calificación correcta del estudiante "<< idx+1 << std::endl;
            std::cin >> califi[idx];
        }

        total = total + califi[idx];   
    }

    std::cout<<"El promedio es: "<< total << std::endl;


    return 0;
}
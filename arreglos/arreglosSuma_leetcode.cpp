#include<iostream>
#include<vector>
using namespace std;

//Give an array of integrers nums and an integer target return indices of the two numbers such that they add up to target.

int vecSum_ind(int miArreglo[], int tam, int target){
    int vec_val_men[tam] = {0};
    int ind_ = 0;
    int valor1 = 0;
    int indice = 0;
    int indice2 = 0;    
    int j = 0;
    int valor_sum = 0;
    int valor2 = 0;

    while(true){
        if(miArreglo[j]<target){
        valor1 = miArreglo[j];
        break;            
        }
        j = j+1;
    }    
    std::cout << valor1 << endl;
    for (int j = 0; j< tam; j++){
        if(miArreglo[j]<target){
            vec_val_men[ind_] = miArreglo[j];
            ind_ = ind_ + 1;
        }
    }

    //std::cout << endl;
    int i = 0;
    while (true){
        valor_sum = valor1 + vec_val_men[i];
        if (valor_sum == target){
            valor2 = vec_val_men[i];
            break;
        }
        i = i+1;
    }
    for (int j = 0; j<tam; j++){
        if(valor1 == miArreglo[j]){
            indice = j;
        }
        if(valor2 == miArreglo[j]){
            indice2 = j;
        }
    }
    //std::cout << "suma: " << valor_sum << endl;
    //std::cout << "indice uno: " << indice << endl;
    //std::cout << "indice dos: " << indice2 << endl;
    int vec_res[] = {valor1, valor2};
    for (int j = 0; j < 2; j++){
        std::cout << vec_res[j] << " ";
    }
    std::cout << endl;        
    return 0;
}

int main(){
    int tam = 3;
    int miArreglo[] = {3,2,4};
    int target = 6;
    vecSum_ind(miArreglo, tam, target);
    return 0;
}
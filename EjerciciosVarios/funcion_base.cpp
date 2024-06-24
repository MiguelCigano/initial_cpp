#include <iostream>

using namespace std;

double potencia(long base, long exponente = 2){
    if(exponente == 2){ 
    return(base*base);
    }
    else{
        double res = base;
        for (long i=1; i<exponente; i++)
            res *= base;
        return res;
    }

}

int main(){
    cout<< "potencia(3) = "<< potencia(3)<<endl;
    cout<< "potencia (3, 5) = "<< potencia(3, 5)<< endl; 
}
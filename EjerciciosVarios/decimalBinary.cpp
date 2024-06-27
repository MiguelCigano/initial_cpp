#include <iostream>
#include <string.h>
using namespace std;

int decimal_binario(int numer, int bin[8]);

int main(){
    int numer;
    int bin[8];
    cout<<"Decimal: "<< endl; 
    cin >> numer;
    decimal_binario(numer, bin);
}

int decimal_binario(int numer, int bin[8]){
    int i;
    int xx;
    int xx2;
    xx = 0;

    for(i=8; i>0; i--){
        bin[i] = 0;
    }

    if(numer<=255){
        while(1){
            xx += numer % 2;
            xx2 = numer % 2;
            bin[i] = xx2;              
            if(numer/2 < 1) break;
            numer = numer / 2;
            // cout<<"Result: "<<numer<<endl;
            i = i+1;
            }
    }   
    else{
        cout<<"ERORR!! Ingrese un número menor a 255"<<endl;
    }
    cout<<"Binary: "<<endl;
    for(i=7; i>=0; i--){
        cout<<bin[i]<< " ";
    }
    cout << endl;
    cout<<"Cantidad de unos: "<<xx<<endl;     
    return 0;  
}

#include <iostream>
#include <string>

using namespace std;

int main(){

    /* Declaramos un puntero, es normal inicar el puntero en NULL para detectar errores fácilmente. */    
    
    char *apuntador = NULL; 

    int x, y, z[10]; 
    /* z se declara como un arreglo de 10 enteros */

    // x = 1;
    // y = 0;

    /* Declaramos un variable tipo caracter, llamada "letra" */
    char letra;

    /* Asignamos la dirección de "letra" a un puntero llamdo "apuntador" */
    apuntador = &letra;

    /* Accedemos a la dirección */
    *apuntador = 'u'; 

    /* np (nuevo apuntador) es un apuntador a int */
    int *np; 
    
    /* ahora np apunta a x */
    np = &x;

    /* el apuntador que esta apuntando a la dirección de x, ahora accede a lo que hay en el espacio de memoria de "x", se asigna a "y" */
    
    y = *np;  
    *np = 100; 
    
    /* El valor de la dirección  apuntada por np, es ahora 100, en este caso x = 100 */

    cout<< letra << endl;
    cout<< x << endl;
    cout<< z << endl;

    /* variables dinámicas, se guardan en la memoria HEAP */
    /* La memoria HEAP no tiene una gestion automática */
    /* Las variables en el HEAP no tienen identificador, se accede a ellas mendiante punteros*/
    double numer = 4.33;
    double *nn = &numer;

    /* el valor apuntado está en el HEAP, siempre que haya un "new" pedimos al sistema operativo que nos reserve un pedazo de memoria en la memoria HEAP */

    int *w = new int; 
    *w = 40;
    w = new int;


}
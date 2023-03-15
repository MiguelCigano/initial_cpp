#include <iostream>
#include <string>

using namespace std;

int main(){
char *apuntador = NULL; // Declaramos un puntero, es normal inicar el puntero en NULL para detectar errores fácilmente.
int x, y, z[10]; // z se declara como un arreglo de 10 enteros
x = 1;
y = 0;

char letra; // Declaramos un variable tipo caracter, llamada "letra"
apuntador = &letra; // Asignamos la dirección de "letra" a un puntero llamdo "apuntador"
*apuntador = 'u'; // Accedemos a la dirección

int *np; /*np (nuevo apuntador) es un apuntador a int*/
np = &x; /* ahora np apunta a x*/
y = *np;  /*el apuntador que esta apuntando a la dirección de x, ahora accede a lo que hay en el espacio de memoria de "x", se asigna a "y"*/
*np = 100; /*El valor de la dirección  apuntada por np, es ahora 100, en este caso x = 100*/

cout<< letra << endl;
cout<< x << endl;
cout<< z << endl;

/*variables dinámicas, se guardan en la memoria HEAP*/
/*La HEAP no tiene una gestion automática*/
/*Las variables en el HEAP no tienen identificador, se accede a ellas mendiante el los punteros*/
double numer = 4.33; /*En este ejemplo las variables estan guardadas en la memoria STACK*/
double *nn = &numer;

int *w = new int; /* el valor apuntado está en el HEAP, siempre que haya un "new" pedimos al sistema operativo que nos reserve un pedazo de memoria en la HEAP*/
*w = 40; /*w está en el STACK*/
w = new int;


}
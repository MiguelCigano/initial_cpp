#include <stdio.h>

/*copia la entrada a la salida*/
/*1a. versón*/

main(){
    int c;
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}
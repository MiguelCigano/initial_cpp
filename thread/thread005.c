#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> /* para malloc y free */


/* Se recibe un parámetro al terminar cada hilo */

void *work2(void *arg);
void *work3(void *arg);

int main(void)
{

    pthread_t thread2;
    long valor2 = 2000000000;
    pthread_t thread3;
    long valor3 = 2000000000;

    long *res3;

    // work2(&valor2);
    // work3(&valor3);
    pthread_create(&thread2, NULL, work2, (void *)&valor2);
    pthread_create(&thread3, NULL, work3, (void *)&valor3);

    pthread_join(thread2, NULL);
    pthread_join(thread3, (void **)&res3);

    printf("res3: %ld", *res3);
    
    /* importante liberar la memoria */
    free(res3);

    return 0;
}


void *work2(void *arg)
{
    long *valor;
    valor = (long *)arg;
    long suma = 0;

    for(int i = 0; i < *valor; i++)
    {
        suma = suma + 1;
    }

    printf("Suma2 : %ld \n", suma);

    return NULL;
}

/* se crea una variable en memoria dinámica para que pueda
recibir la variable suma de work3, ya que suma muere cuando muere 
el ambito de la función work3 */

void *work3(void *arg)
{
    long *valor;
    valor = (long *)arg;
    long suma = 0;

    /* reservo suficiente memoria para un long, y digo que en un un puntero llamado r, 
    apunte a un long */

    /* en C el casteo explicito no es necesario, por lo cual basta con dejar así.
    
    Es importante mencionar que en c malloc retorna un puntero a void */
    long *r = (long *)malloc(sizeof(long));

    for(int i = 0; i < *valor; i++)
    {
        suma = suma + 1;
    }

    printf("Suma3 : %ld \n", suma);

    /* en el dato apuntado por r, que se guarde suma */
    *r = suma;
    /* devuelvo el valor de r que es la dirección de la variable dinámica */

    return (void *)r;
}
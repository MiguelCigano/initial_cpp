#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *work(); /* nota como la función devuelve un void "*" */
void *work2();
void *work3();

int main(void)
{

    pthread_t thread1;  /* id del thread 1 */
    pthread_t thread2;
    pthread_t thread3;
    
    // work();

    /* el cuarto parámetro indica el nombre de la función 
    que va a crear el thread */
    pthread_create(&thread1, NULL, work, NULL);
    /* por definición toda función que crea un thread 
    debe devolver un puntero vacio */
    pthread_create(&thread2, NULL, work2, NULL);

    /* es importante que se creas un thread cheques que se cree bien */
    if( (&thread3, NULL, work3, NULL) != 0 )
    {
        return 3;
    }


    // sleep(2); 
    /* es importante esperar que el thread termine  antes de que se muera el main */

    /* solo que esto no es adecuado por diseño, par eso se usa el join
    el join en este caso pone en pausa el main para que le de tiempo de terminar todos los threads */

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL); 
    /* se pasa por valor porque no necesita modificar 
    el valor, solo necesita saber a quien debe esperar*/


    return 0;
}

void *work()
{
    // sleep(1); /* pone el hilo a dormir en un segundo */
    printf("Hola Thread on work 1 creado \n");
}

void *work2()
{
    printf("Hola Thread on work 2 creado \n");
}
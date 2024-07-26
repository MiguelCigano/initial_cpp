#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *work(); /* nota como la función devuelve un void "*" */
void *work2();

int main(void)
{

    pthread_t thread1;  /* id del thread 1 */
    pthread_t thread2;

    
    // work();

    pthread_create(&thread1, NULL, work, NULL);
    pthread_create(&thread2, NULL, work, NULL);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL); 

    return 0;
}

void *work()
{
    int i;
    int residuo;
    char ch = 'X';

    i = pthread_self(); // devuelve el id del pthread que este ejecutando la función
    residuo = i % 10;
    if( residuo > 5 )
    {
        ch = '0';
    }
    for( i = 0; i < 50 ; i++ )
    {
        fprintf(stdout, "%c", ch);
    }
    /* printf: imprime por consola */
    /* fprintf: imprime un field por consola */
    /* stderr: es un archivo abierto en la pantalla. 1: stdin, 0: stdout */
    /* fprintf(fieldID, , ) */

    pthread_exit(NULL);

}

void *work2()
{
    printf("Hola Thread 2 is working...\n");
}
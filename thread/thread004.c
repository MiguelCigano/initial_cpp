#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


/* Se mide el tiempo usando llamdo de dos funciones
y usando dos hilos para lanzar las mismas dos funciones */

void *work2(void *arg);
void *work3(void *arg);

int main(void)
{

    pthread_t thread2;
    long valor2 = 2000000000;
    pthread_t thread3;
    long valor3 = 2000000000;
    // work2(&valor2);
    // work3(&valor3);
    pthread_create(&thread2, NULL, work2, (void *)&valor2);
    pthread_create(&thread2, NULL, work3, (void *)&valor3);

    pthread_join(thread2, NULL);
    pthread_join(thread2, NULL);

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

void *work3(void *arg)
{
    long *valor;
    valor = (long *)arg;
    long suma = 0;

    for(int i = 0; i < *valor; i++)
    {
        suma = suma + 1;
    }

    printf("Suma3 : %ld \n", suma);


    return NULL;
}
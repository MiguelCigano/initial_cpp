#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> /* para malloc y free */

/* Se hace un ejemplo similar a la thread005.c pero usando un valor aleatorio usando rand */

void *workUnique(void *arg);

int main(void)
{


    pthread_create(&thread1, NULL, workUnique, (void *)&valor1);
    pthread_join(thread1, (void **)&respuesta);

    printf("Respuesta: %ld\n", *respuesta);

    free(respuesta);

    return 0;
}

void *workUnique(void *arg)
{


    return (void *)r;
}

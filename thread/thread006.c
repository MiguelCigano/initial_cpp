#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> /* para malloc y free */

/* Se hace un ejemplo similar a la thread005.c pero usando un valor aleatorio usando rand */

void *workUnique(void *arg);

int main(void)
{
    /* valor log que se pasará a la función que ejecutará el thread*/
    long valor1;

    /* Puntero para obtener una respuesta del thread en el join */
    long *respuesta;

    pthread_t thread1;

    /* La función srand(time(NULL)); se utiliza para inicializar el generador de números aleatorios en C y C++. Aquí te explico cómo funciona:

    srand(unsigned int seed): Esta función establece la semilla para el generador de números aleatorios rand(). Si se llama a rand() sin haber llamado antes a srand(), se usará una semilla predeterminada y los números aleatorios generados serán siempre los mismos cada vez que se ejecute el programa.

    time(NULL): Esta función de la biblioteca ctime devuelve el número de segundos que han pasado desde el 1 de enero de 1970 (la "época" Unix). Cada vez que se llama a time(NULL), se obtiene un valor diferente (a menos que se llame en el mismo segundo).

    srand(time(NULL)): Al pasar el resultado de time(NULL) a srand(), se asegura de que la semilla del generador de números aleatorios sea diferente cada vez que se ejecuta el programa, lo que resulta en una secuencia diferente de números aleatorios */

    srand(time(NULL));

    pthread_create(&thread1, NULL, workUnique, (void *)&valor1);
    pthread_join(thread1, (void **)&respuesta);

    printf("Respuesta: %ld\n", *respuesta);

    free(respuesta);

    return 0;
}

void *workUnique(void *arg)
{
    int valor = rand() % 10 + 1;

    /* segmentation fault generado porque el thread al terminar mueren sus variables locales */
    /* esto se soluciona usando variables dinámicas */

    int *r = malloc(sizeof(int));
    *r = valor;

    /* nota como usamos *r para almacenar el valor de r , esto debido a que lo que almacena r está
    en la memoria HEAP */

    return (void *)r;
}

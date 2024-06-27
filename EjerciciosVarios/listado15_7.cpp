#include <iostream>
#include <cstring>

using namespace std;

/* recibe una lista de cadenas desde el teclado, las ordena y luego las despliega en la pantalla */

#define MAXLINES 25

/* prototipo de funciones */
int getLines(char *lines[]);
void sort(char *p[], int n);
void printStr(char *p[], int n);

/* arreglo de punteros que apunta tipo char */
char *lines[MAXLINES];

int main(void)
{
    int numberLines;

    /* lee las líneas desde el teclado */
    numberLines = getLines(lines);
    
    if(numberLines < 0)
    {
        puts("Memory allocation error");
        exit(-1);
    }

    sort(lines, numberLines);
    printStr(lines, numberLines);

}

int getLines(char *lines[])
{
    int n = 0;
    char buffer[80]; /* almacenamiento temporal para cada línea */
    puts("Enter one line at time; enter a blank when done. ");
    while( (n < MAXLINES) && (std::cin.getline(buffer, sizeof(buffer)) ) && (buffer[0] != '\0') )
    {
        if ( (lines[n] = (char*)malloc(strlen(buffer) + 1)) == NULL )
        {
            return -1;
        }
        strcpy( lines[n++], buffer);
    }
    return n;
}

void sort(char *p[], int n)
{

    char *x;
    for(int a = 1; a < n; a++)
    {
        for(int b = 0; b < n-1; b++)
        {
            if(strcmp(p[b], p[b+1]) > 0)
            {
                x = p[b];
                p[b] = p[b+1];
                p[b+1] = x;
            }
        }
    }
}

void printStr(char *p[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Mensaje: %s\n", p[i]);
    }
}


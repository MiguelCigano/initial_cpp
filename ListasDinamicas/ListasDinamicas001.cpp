#include  <iostream>
#include <string>
#include <limits>

using namespace std;

/* crear una lista que simule una lista de teras pendientes */
/* Cada tarea deberá guardar una descripción y el estado de dicha tarea
*  para saber si la tarea ha sido completada o no */

/* nota que es una lista simplmente enlazada por eso usamos un puntero a la tarea siguiente */
struct Tarea {
    string nombreTarea;
    string descrip;
    bool estado;
    struct Tarea *siguiente;
};

/* la siguiente estructura solo almacena la primera tarea en nodoTarea */
struct Lista {
    int longuitud;
    struct Tarea *nodoTarea;
};

/* --------------------------------------------------------------------------------- */

/* Definición de prototipos */
void agregarTarea(Lista *&lst);
Tarea *crearNodo();
void mostrarLista(Lista *&lst);
void mostrarCantidadTareas(Lista *lst);
Tarea *buscarTareaPorNombre(Lista *lst);

/* En resumen, *& se utiliza cuando quieres pasar un puntero a una función y deseas que la función tenga la capacidad de modificar tanto el contenido al que apunta el puntero como el puntero mismo. */

Tarea *crearNodo()
{
    Tarea *aux = new Tarea;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese titulo de tarea" << std::endl;
    std::getline(std::cin, aux->nombreTarea);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese descripcion de tarea" << std::endl;
    std::getline(std::cin, aux->descrip);

    aux->estado = true;
    aux->siguiente = NULL;

    return aux;

}

void agregarTarea(Lista *&lst)
{
    if (lst == NULL){
        lst = new Lista;
        lst->longuitud = 1;
        lst->nodoTarea = crearNodo();
    }
    else{
        
        Tarea *aux = lst->nodoTarea;
        
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        
        aux->siguiente = crearNodo();
        lst->longuitud = (lst->longuitud)+1;
    }
}

void mostrarLista(Lista *&lst)
{
    if (lst == NULL){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Lista está vacía"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else{

        Tarea *aux = lst->nodoTarea;
        while (aux != NULL){

            std::cout << "Nombre Tarea: " << aux->nombreTarea << std::endl;
            std::cout << "Descripcion: " << aux->descrip << std::endl;
            
            if (aux->estado)
                std::cout << "Tare activa" << std::endl;
            else
                std::cout << "Tare pendiente" << std::endl;
            
            std::cout << "//////////////////////" << std::endl;
            aux = aux->siguiente;
        }
    }
}

void mostrarCantidadTareas(Lista *lst)
{
    if (lst == NULL){
        
        std::cout << "+---------------------+" << std::endl;
        std::cout <<       "Lista vacia"       << std::endl;
        std::cout << "+---------------------+" << std::endl;
    
    }
    else
        std::cout << "Total de tareas: " << lst->longuitud << std::endl;

}

Tarea *buscarTareaPorNombre(Lista *lst)
{
    if (lst == NULL){

        std::cout << "+---------------------+" << std::endl;
        std::cout <<       "Lista vacia"       << std::endl;
        std::cout << "+---------------------+" << std::endl;

    }
    else{

        string nombre;
        int contador = 1;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese nombre de tarea" << std::endl;
        std::getline(std::cin, nombre);

        Tarea *aux = lst->nodoTarea;
        while (aux != NULL){

            if (nombre.compare(aux->nombreTarea)  == 0){
                std::cout << "Nombre de tarea: " << aux->nombreTarea << std::endl;
                std::cout << "Descripcion de tarea: " << aux->descrip << std::endl;
                std::cout << "Numero de tarea: " << contador << std::endl;
                return aux;
            }

            contador += 1;
            aux = aux->siguiente;

        }

        std::cout << "Tarea no registrada" << std::endl;
    }

    return 0; // cambiar por NULL
}

int main(int argc, char **argv)
{   
    Lista *lst = NULL;

    int resp = 0;
    bool continuar = true;

    while (continuar){
        std::cout << "+--------------------------------------------+" << std::endl;
        std::cout << "Ingrese opción a realizar " << std::endl;
        std::cout << " 1) Agregar Tarea " << std::endl;
        std::cout << " 2) Mostrar Tareas "<< std::endl;
        std::cout << " 3) Mostrar cantidad de tareas creadas "<< std::endl;
        std::cout << " 4) Mostrar Tareas completadas " << std::endl;
        std::cout << " 5) Buscar Tarea por su índice "<< std::endl;
        std::cout << " 6) Buscar Tarea por su nombre " << std::endl;
        std::cout << " 7) Eliminar Tarea " << std::endl;
        std::cout << " 8) Reiniciar Lista " << std::endl;
        std::cout << " 9) Terminar Tarea "<< std::endl;
        std::cout << "10) Mostrar Tareas incompletas "<< std::endl;
        std::cout << "11) Salir del programa " << std::endl;
        std::cout << "+--------------------------------------------+" << std::endl;

        std::cin >> resp;

        switch(resp){
            case  1: agregarTarea(lst); break;
            case  2: mostrarLista(lst); break;
            case  3: mostrarCantidadTareas(lst); break;
            case  4: ; break;
            case  5: ; break;
            case  6: buscarTareaPorNombre(lst); break;
            case  7: ; break;
            case  8: ; break;
            case  9: ; break;
            case 10: ; break;
        }

        // std::cout << lst->nodoTarea->nombreTarea << std::endl;
        std::cin.get();
        std::cin.get();
        system("clear");
        

    }

    return 0;
}

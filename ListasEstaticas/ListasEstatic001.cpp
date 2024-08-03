#include <iostream>
using namespace std;

/* ----------------------------------------------------- */
/* Clinica dental */
/* Crear una lista para agregar pacientes */
/* La clina atiende a 20 personas por día entre 10 y 30 min por persona */
/* La agenda considera los siguientes datos: nombre, edad, sexo, fecha y hora de la consulta, total a pagar, y servicios realizados */

/* Se consideran los siguientes tratamientos */
/* 1) Limpieza dental: $1,300 */
/* 2) Tapadura de caries: $1,500 */
/* 3) Extracción de muelas: $3,000 */
/* 4) Blanqueamiento dental: $4,000 */
/* ----------------------------------------------------- */

/* definimos los precios como variables globales */
#define precioLimpieza 1300
#define precioTapadura 1500
#define precioExtraccion 3000
#define precioBlanqueamiento 4000
#define numeroPacientes 20

struct fecha {
    int anio;
    int mes;
    int dia;
    int hora;
    int min;
};

struct servicio {
    bool limpieza;
    bool blanqueamiento;
    int extraccion;
    int tapadura;
};

/* se crea una lista de 20 estructuras tipo pacientes de forma global */
struct pacientes {
    string nombre;
    int edad;
    string sexo;
    int total;
    struct fecha atencion;
    struct servicio svc;
}lst[numeroPacientes];

void iniciarPacientes()
{
    for (int i = 0; i < numeroPacientes; i++){
        
        lst[i].nombre = " ";
        lst[i].edad = 0;
        lst[i].sexo = " ";
        lst[i].total = 0;

        lst[i].atencion.anio = 0;
        lst[i].atencion.mes = 0;
        lst[i].atencion.dia = 0;
        lst[i].atencion.hora = 0;
        lst[i].atencion.min = 0;

        lst[i].svc.blanqueamiento = false;
        lst[i].svc.extraccion = false;
        lst[i].svc.limpieza = 0;
        lst[i].svc.tapadura = 0;
    }
}

void mostrarPacientes()
{
    for (int i = 0; i < numeroPacientes; i++){

        std::cout << "Nombre: " << lst[i].nombre << std::endl;
        std::cout << "Edad: " << lst[i].edad << std::endl;
        std::cout << "Sexo: " << lst[i].sexo << std::endl;
        std::cout << "Total: " << lst[i].total << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Limpieza: " << lst[i].svc.limpieza << std::endl;
        std::cout << "Blanqueamiento: " << lst[i].svc.blanqueamiento << std::endl;
        std::cout << "Tapadura: " << lst[i].svc.tapadura << std::endl;
        std::cout << "Extracción: " << lst[i].svc.extraccion << std::endl;
        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "Fecha de atención programada: " << lst[i].atencion.anio << "/"  << lst[i].atencion.mes << "/" << lst[i].atencion.dia << std::endl;

    }
    
}

int comprobarAgenda()
{   
    int i = 0;
    while (i<numeroPacientes){
        
        if (lst[i].nombre == " "){
            std::cout << "Espacio disponible: " << i << std::endl;

            return i+1;
        }
        else
            std::cout << "No hay espacio disponibles hoy" << std::endl;

        i++;        
    }
    
    return -1;
}



int main(int argc, char **argv)
{
    iniciarPacientes();
    mostrarPacientes();

    return 0;
}



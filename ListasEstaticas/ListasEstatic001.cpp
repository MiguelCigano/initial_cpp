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
    string  nombre;
    int edad;
    string sexo;
    int total;
    struct fecha atencion;
    struct servicio svc;
}lst[numeroPacientes];

int main(int argc, char **argv)
{
    for (int i = 0; i < numeroPacientes; i++)
    {
        std::cout<< "Nombre: " << pacientes[i].nombre << std::endl;
        std::cout<< "Edad: " << pacientes[i].edad << std::endl;
        std::cout<< "Sexo: " << pacientes[i].sexo << std::endl;
        std::cout<< "Total: " << pacientes[i].total << std::endl;
        std::cout<< "//////////////////////////// " << std::endl;
        std::cout<< " " << std::endl;
        std::cout<< " " << std::endl;

    }

}



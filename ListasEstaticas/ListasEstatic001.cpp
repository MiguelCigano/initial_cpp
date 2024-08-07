#include <iostream>
#include <string>
#include <limits> 

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

/* Prototipos de funciones */
void iniciarPacientes();
void mostrarPacientes();
int comprobarAgenda();
void mostrarHoraDisponible(int hora, int min, int indice);
void agregarElemento();
void ingresarPaciente(int it);
void selectServicio();

 
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
    std::string sexo;
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

        static int horaInicial = 7;
        /* contador se usa para evitar más if, y diferenciar la hora de comida */
        static int contador = 0;

        if (i%2 == 0 && contador != 10){
            lst[i].atencion.hora = ++horaInicial;
            lst[i].atencion.min = 0;
        }
        else if (contador == 10) {
            lst[i].atencion.hora = horaInicial += 2;
        }
        else{
            lst[i].atencion.hora = horaInicial;
            lst[i].atencion.min = 3;
        }

        contador++;

        lst[i].svc.blanqueamiento = false;
        lst[i].svc.extraccion = false;
        lst[i].svc.limpieza = 0;
        lst[i].svc.tapadura = 0;
    }
}

void mostrarPacientes()
{
    for (int i = 0; i < numeroPacientes; i++){

        std::cout << "+-----------------------------------+" << std::endl;
        std::cout << "Nombre: " << lst[i].nombre << std::endl;
        std::cout << "Edad: " << lst[i].edad << std::endl;
        std::cout << "Sexo: " << lst[i].sexo << std::endl;
        std::cout << "Total: " << lst[i].total << std::endl;
        std::cout << std::endl;
        std::cout << "Limpieza: " << lst[i].svc.limpieza << std::endl;
        std::cout << "Blanqueamiento: " << lst[i].svc.blanqueamiento << std::endl;
        std::cout << "Tapadura: " << lst[i].svc.tapadura << std::endl;
        std::cout << "Extracción: " << lst[i].svc.extraccion << std::endl;
        std::cout << std::endl;
        std::cout << "Fecha de atención programada: " << lst[i].atencion.anio << "/"  << lst[i].atencion.mes << "/" << lst[i].atencion.dia << "   Hora de atención programada: " << lst[i].atencion.hora << ":" << lst[i].atencion.min << "0" << std::endl;

        if (i == 9){
            std::cout << std::endl;
            std::cout << "||||||||||||||||||||||||||||||||||||||||" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "              FOOD TIME               " << std::endl;
            std::cout << "            13:00 - 14:00               " << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "||||||||||||||||||||||||||||||||||||||||" << std::endl;
            std::cout << std::endl;
        }

    }
    
}

int comprobarAgenda()
{   
    int i = 0;
    while (i < numeroPacientes){
        
        if (lst[i].nombre == " "){
            // std::cout << "Espacio disponible: " << i+1 << std::endl;
            return i+1; // retorna indice disponible
        }
        else{
            std::cout << "No hay espacio disponibles hoy" << std::endl;
            return -1;
        }

        i++;    
    }

    return -1;
     
}

void ingresarPaciente(int it)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
    std::cout << "Ingrese nombre: ";
    std::getline(std::cin, lst[it].nombre);

    std::cout << "Ingrese edad: ";
    std::cin >> lst[it].edad;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese sexo: ";
    std::getline(std::cin, lst[it].sexo);
    
}

void selectServicio(int it)
{
    int respuesta = 0;
    while(respuesta!=5){

        std::cout << "1) Limpieza dental, SI: 1 / NO: 0." << std::endl;
        std::cout << "2) Tapadura de caries." << std::endl;
        std::cout << "3) Extracción de muelas." << std::endl;
        std::cout << "4) Blanqueamiento dental. SI: 1 / NO: 0." << std::endl;
        std::cout << "5) Ninguno otro servicio." << std::endl;

        std::cin >> respuesta;

        switch (respuesta)
        {
            case 1: std::cin >> lst[it].svc.limpieza; break;
            case 2:
                std::cout << "¿Cuantas tapaduras?: ";
                std::cin >> lst[it].svc.tapadura;
                break;
            case 3: 
                std::cout << "¿Cuantas extraciones?: ";
                std::cin >> lst[it].svc.extraccion;
                break;
            case 4: std::cin >> lst[it].svc.blanqueamiento; break;
            default:
                std::cout << "Servicio no valido" << std::endl;
        }

    }
}

void mostrarHoraDisponible(int hora, int min, int indice)
{
    int it = 0;

    for (int i = 0; i < numeroPacientes; i++){
        
        if ((hora == lst[i].atencion.hora) && (min == lst[i].atencion.min)){
            if (lst[i].nombre == " "){

                it = i;

                std::cout << std::endl;
                std::cout << "Hora selecionado disponible" << std::endl;
                std::cout << std::endl;
                
                ingresarPaciente(it);

                std::cout << "Ingrese tipo de servicio" << std::endl;

                selectServicio(it);
            }

        else
            std::cout << "Horario sugerido: " << lst[indice].atencion.hora << ":" << lst[indice].atencion.min << "0" << std::endl;
        }
    }

}

void agregarElemento()
{

    int hora;
    int min;

    int indice = comprobarAgenda();

    if (indice != -1){
        std::cout << "Ingrese hora: "<< std::endl;
        std::cin >> hora;
        std::cout << "Ingrese minutos: " << std::endl;
        std::cin >> min;
        min = min/10;
    }
    else
        comprobarAgenda();

    mostrarHoraDisponible(hora, min, indice);

    // lst[0]  ----> 8:00  --  8:25
    // lst[1]  ----> 8:30  --  8:55
    // lst[2]  ----> 9:00  --  9:25
    // lst[3]  ----> 9:30  --  9:55
    // lst[4]  ----> 10:00 -- 10:25
    // lst[5]  ----> 10:30 -- 10:55
    // lst[6]  ----> 11:00 -- 11:25
    // lst[7]  ----> 11:30 -- 11:55
    // lst[8]  ----> 12:00 -- 12:25
    // lst[9]  ----> 12:30 -- 12:55
    // lst[10] ----> 14:00 -- 14:25
    // lst[11] ----> 14:30 -- 14:55
    // lst[12] ----> 15:00 -- 15:25
    // lst[13] ----> 15:30 -- 15:55
    // lst[14] ----> 16:00 -- 16:25
    // lst[15] ----> 16:30 -- 16:55
    // lst[16] ----> 17:00 -- 17:25
    // lst[17] ----> 17:30 -- 17:55
    // lst[18] ----> 18:00 -- 18:25
    // lst[19] ----> 18:30 -- 18:55
}

int main(int argc, char **argv)
{
    iniciarPacientes();
    mostrarPacientes();
    agregarElemento();
    mostrarPacientes();

    return 0;
}


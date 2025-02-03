#include <iostream>
#include <string>

/*
 * Un clase puede definirse sin necesidad del
 * constructor.
 * Se usa una constructor vacío de manera automática
 * falta meterle mano un poco
*/

class cuentaBancaria {
    public:
        cuentaBancaria(std::string cuenta, int saldo);  // constructor
        void agregar_dinero();
        void retirar_dinero(int retiro);
        int mostrar_saldo();
    private:
        std::string num_cuenta;
        int saldo_actual;
};

// definición del constructor
cuentaBancaria::cuentaBancaria(std::string cuenta, int saldo) {
    num_cuenta = cuenta;
    saldo_actual = saldo;
}

void cuentaBancaria::agregar_dinero() {
    int saldo_agregado;
    std::cout << "Agrega saldo..." << std::endl;
    std::cin >> saldo_agregado;
    std::cout << "Agregando:" << saldo_agregado << std::endl;
    saldo_actual += saldo_agregado; 
}
void cuentaBancaria::retirar_dinero(int retiro) {
    saldo_actual -= retiro;
}

int cuentaBancaria::mostrar_saldo() {
    return saldo_actual;
}

int main(int argc, char **argv)
{
    int retiro;
    cuentaBancaria cuenta("123", 1500);
    std::cout << "Cuenta bancaria..." << std::endl;
    std::cout << cuenta.mostrar_saldo() << std::endl;
    cuenta.agregar_dinero();
    std::cout << cuenta.mostrar_saldo() << std::endl;
    std::cout << "retiro..." << std::endl;
    std::cout << "cuanto deseas retirar?" << std::endl;
    std::cin >> retiro;
    cuenta.retirar_dinero(retiro);
    std::cout << cuenta.mostrar_saldo() << std::endl;

}
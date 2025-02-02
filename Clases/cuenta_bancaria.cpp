#include <iostream>
#include <string>

/*
 * Un clase puede definirse sin necesidad del
 * constructor.
 * Se usa una constructor vacío de manera automática
*/

class cuentaBancaria {
    public:
        cuentaBancaria(std::string cuenta, int saldo);  // constructor
        void agregar_dinero();
        void retirar_dinero();
        void mostrar_saldo();
    private:
        std::string num_cuenta;
        int saldo_actual;
};

// definición del constructor
cuentaBancaria::cuentaBancaria(std::string cuenta, int saldo) {
    num_cuenta = cuenta;
    saldo_actual = saldo;
}

void cuentaBancaria::agregar_dinero(){
    int saldo_agregado;
    std::cout << "Agrega saldo..." << std::endl;
    std::cin >> saldo_agregado;
    std::cout << "Agregando:" << saldo_agregado << std::endl;
    saldo_actual += saldo_agregado; 
}

void cuentaBancaria::mostrar_saldo(){
    std::cout << saldo_actual << std::endl;
}

int main(int argc, char **argv)
{
    cuentaBancaria cuenta("123", 1500);
    std::cout << "Cuenta bancaria..." << std::endl;
    cuenta.mostrar_saldo();
    cuenta.agregar_dinero();
    cuenta.mostrar_saldo();
}
#include<iostream>

void modified_by_reference(int &x) { // <- Aquí si es necesario especificar!
    x = x + 1;
    std::cout << "x in fn: " << x << std::endl;
    std::cout << "x in fn address: " << &x << std::endl;
}

int main() {
    int x = 10;
    modified_by_reference(x); // <- nota que aquí solo debo pasar 
						      // el objeto como argumento a la 
						      // función,  es el compilador quien toma
                              // la referencia de ese objeto.

    std::cout << "x in main: " << x << std::endl;
    std::cout << "x in main address: " << &x << std::endl;

    return 0;
}
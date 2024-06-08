#include <iostream>

class CAT
{
    public:
        int age;
        int weight;

};

int main(){
    CAT Pedrito;
    Pedrito.age = 5;           // -------- Asignacion a una variable miembro
    std::cout << "Pedrito es un gato el cual tiene ";
    std::cout << Pedrito.age << " años de edad";
    return 0;
}


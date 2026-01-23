#include <iostream>

class Cat
{
    public:
        int age;
        int weight;
};

struct YukoStr
{
    int age2;
    int weight2;
};

int main(){
    Cat Yuko;
    YukoStr YukoStr;
    Yuko.age = 5;           // -------- Asignacion a una variable miembro
    YukoStr.weight2 = 25;
    std::cout << "Yuko es un gato el cual tiene ";
    std::cout << Yuko.age << " años de edad";
    // std::cout << (*Yuko) << std::endl;
    return 0;
}


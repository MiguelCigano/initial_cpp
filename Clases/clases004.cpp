/* creando miembros y datos sobre un almacenamiento libre */
/* Semana 2, día 8 */

#include <iostream>

class simpleCat
{
    public:
    simpleCat();
    ~simpleCat();
    int getAge()    const { return *itsAge; } // implementación en línea
    void setAge(int age) { *itsAge = age; }

    // int getWeight() const { return *itsWeight; }
    int getWeight();
    void setWeight(int weight);

    private:
    int *itsAge;
    int *itsWeight;
};

// se define el constructor
simpleCat::simpleCat()
{
    itsAge = new int(4);
    itsWeight = new int(30);
}

// definimos el destructor
simpleCat::~simpleCat()
{
    delete itsAge;
    delete itsWeight;
}

/* los siguientes dos métodos públicos son implementados fuera de línea, es decir, fuera de la clase */
/* notese que tambine quitamos la caracteristica constante del método */
int simpleCat::getWeight()
{
    return *itsWeight;
}

void simpleCat::setWeight(int weight)
{
    *itsWeight = weight;
}

int main(void)
{   
    simpleCat *pepe = new simpleCat;

    std::cout << "pepe tiene " << pepe->getAge() << " años de edad " << std::endl;

    pepe->setAge(20);

    std::cout << "pepe tiene " << pepe->getAge() << " años de edad " << std::endl;

    std::cout << "pepe pesa " << pepe->getWeight() << " kilos " << std::endl;

    pepe->setWeight(8);

    std::cout << "pepe pesa " << pepe->getWeight() << " kilos " << std::endl;



    return 0;
}
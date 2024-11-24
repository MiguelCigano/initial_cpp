#include <iostream>

const int EXPAND = 2;

class myVector {
    private:
        double *data;           // puntero a los datos del arreglo
        size_t size;            // número de elementos actualmente en el "vector".
        size_t capacity;        // capacidad total del vector
    public:
        // constructor: inicializa el vector con capacidad inicial
        myVector(size_t init_capacity = EXPAND)
        {
            data     =  new double[init_capacity]; // arreglo tipo double con tamano inicial
            size     =  0;                         // contador de elementos del vector
            capacity =  init_capacity;
        }
        // destructor: para liberar memoria asignada
        ~myVector() 
        {
            delete[] data;                          // forma de liberar memoria para el array
        }
        double *get_data() const    { return data;     }
        size_t get_size() const     { return size;     }    // importante usar const en getters
        size_t get_capacity() const { return capacity; }
        void push_back(double val);
        void print_vector();

};

void myVector::push_back(double val) 
{
    if (size == capacity) {
        capacity = capacity * EXPAND;
        double *new_data = new double[capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;                         // libera  antigua memoria
        data = new_data;                       // asigna la nueva memoria
    }
    data[size++] = val;                        // agrega el nuevo valor al array
}

void myVector::print_vector()
{
    for (size_t i = 0; i < size; ++i) {
        std::cout << data[i] << ", "; 
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    myVector vec;
    vec.push_back(2.2);
    vec.push_back(3.2);
    vec.push_back(4.2);
    vec.print_vector();

    size_t size_vec = vec.get_size();
    std::cout << "Vector size: "<< size_vec << std::endl;
    size_t memory_used = size_vec * sizeof(double);
    std::cout << "Memory used for data: " << memory_used << "bytes" << std::endl;
    size_t capacity_vec = vec.get_capacity();
    size_t memory_enable = capacity_vec * sizeof(double);
    std::cout << "Memory enable: " << memory_enable << "bytes" << std::endl; 

    std::cout << std::endl;

    vec.push_back(5.3);
    vec.push_back(6.3);
    vec.push_back(7.3);
    vec.print_vector();

    size_vec = vec.get_size();
    std::cout << "Vector size: "<< size_vec << std::endl;
    memory_used = size_vec * sizeof(double);
    std::cout << "Memory used for data: " << memory_used << "bytes" << std::endl;
    capacity_vec = vec.get_capacity();
    memory_enable = capacity_vec * sizeof(double);
    std::cout << "Memory enable: " << memory_enable << "bytes" << std::endl; 

    return 0;
}


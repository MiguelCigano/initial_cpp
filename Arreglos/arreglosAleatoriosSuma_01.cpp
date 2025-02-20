#include <iostream>
#include <cstdlib>
#include <ctime>

void suma_vector(int vector_a[], int vector_b[], int vector_r[], const int size) {
    int i = 0;
    while (i < size) {
        vector_r[i] = vector_a[i] + vector_b[i];
        i++;
    }
}

void set_vector(int vector[], const int size) {
    int i = 0;  
    while (i < size) {
        vector[i] = std::rand() %100;
        i++;
    }
}

void show_vector(int vector[], std::string name, const int size) {
    int i = 0;
    while (i < size) {
        if (i == 0) {
            std::cout << "vector "<< name << ": " << vector[i] << " ";
            i++;   
        }
        else {
        std::cout << vector[i] << " ";
        i++;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{   
    std::srand(std::time(nullptr)); // semilla basada en tiempor real actual
    const int size = 10;
    int a[size];
    int b[size];
    int r[size];
    set_vector(a, size);
    show_vector(a, "A", size);
    set_vector(b, size);
    show_vector(b, "B", size);
    suma_vector(a, b, r, size);
    show_vector(r, "RES", size);
    return 0;
}
#include <iostream>

/*
 * ~ Matrix dinámica y suma de elementos
 * 1. Solicita al usuario el número de filas y columnas de una matriz.
 * 2. Reserva memoria dinámica para almacenar los datos.
 * 3. Pida al usuario que ingrese los valores de la matriz.
 * 4. Calcule la suma de todos los elementos.abs
 * 5. Libere correctamente la memoria,
*/

void show_arrows_columns(int *rows_ptr, int *columns_ptr) {
    std::cout << "rows: " << *rows_ptr << std::endl;
    std::cout << "columns: " << *columns_ptr << std::endl;
}

int** mem_request(int *rows_ptr, int *columns_ptr) {
    int **mtrx = new int *[*rows_ptr]; // set pointer's array dynamic
    for (int i = 0; i < *rows_ptr; i++) {
        mtrx[i] = new int[*columns_ptr];
    }
    return mtrx;
}

void mem_free(int **mtrx, int *rows_ptr) {
    for (int i = 0; i < *rows_ptr; i++) {
        delete[] mtrx[i]; // free arrow 
    }
    delete[] mtrx; // free pointer's array
}

int main (int argc, char **argv) {

    int rows_;
    int *rows_ptr = &rows_;
    int columns_;
    int *columns_ptr = &columns_;
    
    std::cout << "Enter number of rows: ";
    std::cin >> *rows_ptr;
    std::cout << "Enter number of columns: ";
    std::cin >> *columns_ptr;

    show_arrows_columns(rows_ptr, columns_ptr);
    if (*rows_ptr > 0 and *columns_ptr > 0) {
        int **mtrx = mem_request(rows_ptr, columns_ptr);
        mem_free(mtrx, rows_ptr);
    }
    else
        std::cout << "rows and colums should be differents to zero \n";

    return 0;
}
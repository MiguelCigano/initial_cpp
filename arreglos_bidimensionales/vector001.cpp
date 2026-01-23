#include <iostream>
#include <vector>

using namespace std;

// Se define el protipo 
// const nos indica que la función no modifica el contenido de vector
void imprimeMatrizReferencia(const vector<vector<double>> &matrix);
void imprimeMatrizValor(const vector<vector<double>> matrix);

int main(void){

    vector<vector<double>> matrix;

    // inicializando el tamaño de una matriz 3x3
    matrix.resize(3, vector<double>(3));

    /* asignando valores a la matriz */
    matrix[0][0] = 10.0;
    matrix[0][1] = 22.0;
    matrix[0][2] = 3.0;
    matrix[1][0] = 4.0;
    matrix[1][1] = 5.0;
    matrix[1][2] = 6.0;
    matrix[2][0] = 7.0;
    matrix[2][1] = 8.0;
    matrix[2][2] = 9.0;

    // existen otras formas de inicializar una matriz
    vector<vector<double>> matrix2;
    matrix.resize(3, vector<double>(3));

    // inicializa una matriz con puros ceros
    vector<vector<double>> matrix3(3, vector<double>(3, 0.0));

    vector<vector<double>> matrix4 = {
    {10.0, 20.0, 30.0},
    {40.0, 50.0, 60.0},
    {7.0, 80.0, 90.0}
    };

    /* para imprimir la matriz */

    for(size_t i = 0; i < matrix3.size(); i++)
    {
        for(size_t j = 0; j < matrix3.size(); j++)
            std::cout << matrix3[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << std::endl;

    imprimeMatrizReferencia(matrix4);

    std::cout << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << std::endl;
    
    imprimeMatrizValor(matrix);

    std::cout << std::endl;

    return 0;
}

/* Usa bucles basados en rangos 'range-based for loops' para iterar sobre las filas */ 
/* y los elementos de cada fila */
/* Nota que esta función recibe el valor por referencia, lo cual es más eficiente porque no se */
/* Trabaja con una copia */
void imprimeMatrizReferencia(const vector<vector<double>> &matrix)
{
    for(const auto &row: matrix)
    {
        for(double value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

}

void imprimeMatrizValor(const vector<vector<double>> matrix)
{
    for(const auto &row: matrix)
    {
        for(double value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

}
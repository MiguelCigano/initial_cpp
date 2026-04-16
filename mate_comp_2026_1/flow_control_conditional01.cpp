#include <iostream>

// Using oepratopr
// | Operador | Significado       | Ejemplo  | Resultado                  |
// | -------- | ----------------- | -------- | -------------------------- |
// |   ==     | Igual a           |   a == b | true si son iguales        |
// |   !=     | Diferente de      |   a != b | true si son diferentes     |
// |   >      | Mayor que         |   a > b  | true si a es mayor         |
// |   <      | Menor que         |   a < b  | true si a es menor         |
// |   >=     | Mayor o igual que |   a >= b | true si a es mayor o igual |
// |   <=     | Menor o igual que |   a <= b | true si a es menor o igual |

// |   !      | Negacion
// |  ||      | OR
// |  &&      | AND


void suma() {
    // declaracion de la funcion
}

int main() {
    int a = 10;
    int b = 20;

    // control de flujo condicional
    if (false)  // condicional
    {
        // declaracion if
        std::cout << "declaracion if" << std::endl;
    }
    else if (!(a <= 9) && !(a < b)) {
        // declaracion else
        std::cout << "declaracion else if" << std::endl;
    }
    else {
        std::cout << ":( " << std::endl;
    }

}

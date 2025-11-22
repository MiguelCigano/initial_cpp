#include <iostream>

/**
 * @brief Realiza la operación lógica AND, corresponde a la CONJUCIÓN
 * de dos proposiciones.
 * @param p Primera proposición que recibe la función, tipo bool.
 * @param q Segunda proposición que recibe la función, tipo bool.
 * @return  un booleano como resultado de aplicar la operación AND a las
 * proposiciones p y q.
 */
bool fn_and(bool p, bool q) {
    return p && q;
}

/**
 * @brief Realiza la operación lógica OR, corresponde a la DISJUNCIÓN
 * de dos proposiciones.
 * @param p Primera proposición que recibe la función, tipo bool.
 * @param q Segunda proposición que recibe la función, tipo bool.
 * @return un booleano como el resultado de aplicar la operación OR a las
 * proposiciones p y q.
 */
bool fn_or(bool p, bool q) {
    return p || q;
}

/**
 * @brief Realiza la operación lógica NOT, corresponde a la NEGACIÓN
 * de una sola proposición.
 * @param x Única proposición que recibe la función, tipo bool.
 * @return un booleano como el resultado de aplicar la operación NOT a la
 * proposición x.
 */
bool fn_not(bool x) {
    return !x;
}

/**
 * @brief Realiza una proposición compuesta.
 * @param p Primera proposición que recibe la función, tipo bool.
 * @param q Segunda proposición que recibe la función, tipo bool.
 * @return ...
 */
bool fn_prop_comp(bool t, bool u) {
    return !(t && u);
}

/**
 * @brief Realiza la conversión de un tipo booleano a un letra.
 * Si recibe un booleano true (1) retorna V, si recibe un booleano false (0)
 * retorna una F.
 * @param x valor booleano que recibe la función, tipo bool.
 * @return un string, V o F dependiendo del valor booleano que recibe la función.
 */
std::string bool_to_str(bool x) {
    return x ? "V" : "F";
}

int main() {
    std::cout << "Usando una sola función:" << std::endl;
    std::cout << bool_to_str(fn_prop_comp(false, false)) << std::endl;
    std::cout << bool_to_str(fn_prop_comp(false, true)) << std::endl;
    std::cout << bool_to_str(fn_prop_comp(true, false)) << std::endl;
    std::cout << bool_to_str(fn_prop_comp(true, true)) << std::endl;

    std::cout << std::endl; // Para generar un renglón de espacio
    std::cout << "--------------" << std::endl; // Para generar un línea
    std::cout << std::endl; // Para generar un renglón de espacio

    std::cout << "Usando funciones que hacen operaciones separadas:" << std::endl;
    std::cout << bool_to_str(fn_not(fn_and(false, false))) << std::endl;
    std::cout << bool_to_str(fn_not(fn_and(false, true))) << std::endl;
    std::cout << bool_to_str(fn_not(fn_and(true, false))) << std::endl;
    std::cout << bool_to_str(fn_not(fn_and(true, true))) << std::endl;

    return 0;
}
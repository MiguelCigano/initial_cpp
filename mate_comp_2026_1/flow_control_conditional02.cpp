#include <iostream>

// Negation ! (NOT)
bool ng(bool p) {
    return !p;
}
// Conjugation &&  (AND)
bool cj(bool p, bool q) {
    return (p && q);
}

// Disjuntion || (OR)
bool dj(bool p, bool q) {
    return (p || q);
}

int main() {

    std::cout << "\nTabla de verdad de negacion" << std::endl;
    std::cout << "Negacion de 1 (true):       " << ng(true) << std::endl;
    std::cout << "Doble negacion de 1 (true): " << ng(ng(true)) << std::endl;

    std::cout << "\nTabla de verdad de la conjugación" << std::endl;
    std::cout << "Conju de 0 (false) && 0 (false): " << cj(false, false) << std::endl;
    std::cout << "Conju de 0 (false) && 1 (true):  " << cj(false, true) << std::endl;
    std::cout << "Conju de 1 (true) && 0 (false):  " << cj(true,  false) << std::endl;
    std::cout << "Conju de 1 (true) && 1 (true):   " << cj(true,  true) << std::endl;

    std::cout << "\nTabla de verdad de la Disyuncion" << std::endl;
    std::cout << "Disyu de 0 (false) || 0 (false): " << dj(false, false) << std::endl;
    std::cout << "Disyu de 0 (false) || 1 (true):  " << dj(false, true) << std::endl;
    std::cout << "Disyu de 1 (true)  || 0 (false): " << dj(true,  false) << std::endl;
    std::cout << "Disyu de 1 (true)  || 1 (true):  " << dj(true,  true) << std::endl;

    return 0;
}
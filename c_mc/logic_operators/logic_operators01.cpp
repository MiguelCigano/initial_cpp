#include <iostream>

bool fn_and(bool p, bool q) {
    if (p && q) { // (...)
        return true;
    }
    else {
        return false;
    }
}

bool fn_or(bool p, bool q) {
    if (p || q) { // (...)
        return true;
    }
    else {
        return false;
    }
}

bool fn_not(bool x){
    if (x == true) {
        x = false;
        return x;
    }
    else {
        x = true;
        return x;
    }
}
int main() {
    // variables globales
    bool p = true;
    bool q = false;

    bool result_and = fn_and(p, q);
    bool result_or = fn_or(p, q);
    bool result_not =fn_not(p);

    std::cout << "p("<< p <<") and q("<< q <<"): " << result_and << std::endl;
    std::cout << "p("<< p <<") or  q("<< q <<"): " << result_or << std::endl;
    std::cout << "p("<< p <<") not: " << result_not << std::endl;
    return 0;
}
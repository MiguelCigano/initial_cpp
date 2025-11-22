#include <iostream>

using namespace::std;

// OPCION 1: Usar funciones que realicen
// las operaciones lógicas por separado.
bool fn_and(bool p, bool q){
    return p && q;
}

bool fn_condi(bool p, bool q){
    return !p || q;
}

std::string bool_to_str(bool x) {
    return x ? "V" : "F";
}

// OPCION 2: Usar una función que realice la
// operación compuesta
bool fn_comp(bool p, bool q, bool r) {
    return !(p) || (q && r);
}

int main(){
    cout << bool_to_str(fn_comp(false, false, false)) << endl;
    cout << bool_to_str(fn_comp(false, false, true)) << endl;
    cout << bool_to_str(fn_comp(false, true, false)) << endl;
    cout << bool_to_str(fn_comp(false, true, true)) << endl;
    cout << bool_to_str(fn_comp(true, false, false)) << endl;
    cout << bool_to_str(fn_comp(true, false, true)) << endl;
    cout << bool_to_str(fn_comp(true, true, false)) << endl;
    cout << bool_to_str(fn_comp(true, true, true)) << endl;

    return 0;
}

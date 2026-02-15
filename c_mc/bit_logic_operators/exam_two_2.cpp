#include <iostream>

using namespace::std;

// Usaremos solo la opcion de una operación
// compuesta, debido a que tiene varias operaciones

bool fn_comp(bool p, bool q, bool r) {
    return  !((!p && !q) && !r); 
}

std::string bool_to_str(bool x){
    return x ? "V" : "F";
}

int main() {
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


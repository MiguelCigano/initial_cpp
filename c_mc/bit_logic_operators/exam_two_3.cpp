#include <iostream>

using namespace::std;

bool fn_condi(bool p, bool q){
    return !p || q; 
}

std::string bool_to_str(bool x){
    return x ? "V" : "F";
}

int main() {
    cout << bool_to_str(fn_condi(fn_condi(false, false), false)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(false, false), true)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(false, true), false)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(false, true), true)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(true, false), false)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(true, false), true)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(true, true), false)) << endl;
    cout << bool_to_str(fn_condi(fn_condi(true, true), true)) << endl;
    
    return 0;
}



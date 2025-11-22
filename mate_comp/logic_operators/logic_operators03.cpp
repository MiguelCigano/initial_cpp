#include <iostream>
#include <cstdint>

bool fn_and(bool p, bool q) {
    return p && q;
}

bool fn_or(bool p, bool q) {
    bool r = p || q;
    return r;
}

std::string bool_to_str(bool value) {
    return value ? "V" : "F";
}

bool fn_not(bool x) {
    return !x;
}

bool fn_prop_comp(bool p, bool q, bool r) {
    return (!p || q) && (r || p);
}

int main() {
    bool values[2] = {false, true};

    for(int i = 0; i < 2; i++) { // for loop
        bool p = values[i];
        for(bool q : values) { // for-range
            for(bool r : values) {
                // std::cout << bool_to_str(p) << " AND " << bool_to_str(q) << " AND " << bool_to_str(r) << " = " << bool_to_str(fn_and(fn_and(r, q), p)) << std::endl;
                std::cout << "Proposicion Compuesta: " << bool_to_str(fn_prop_comp(p, q, r)) << std::endl;
            }
        }
    }
    return 0;
}
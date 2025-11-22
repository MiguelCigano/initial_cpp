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

int main() {
    bool values[2] = {false, true};

    for(int i = 0; i < 2; i++) { // for loop
        bool p = values[i];
        for(bool q : values) { // for-range
            std::cout << bool_to_str(p) << " AND " << bool_to_str(q) << " = " << bool_to_str(fn_not(fn_and(p, q))) << std::endl;
        }
    }
    return 0;
}
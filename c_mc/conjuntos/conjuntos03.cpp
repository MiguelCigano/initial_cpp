#include <iostream>
#include <vector>

void modified_vec_auto(std::vector<int> &A) {
    for (auto &x : A) {
        x += 1; 
    }
}

int print_vec_auto(const std::vector<int> &A) {
    for(const auto &x : A) {
        std::cout << x << " "; 
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    std::vector<int> A = {2, 3, 4, 5, 6};

    modified_vec_auto(A);
    int r = print_vec_auto(A);

    /**
     * Esta sección del programa es solo para 
     * validar que la función de print terminó bien
     * Pueden omitirla.
     */
    if (r == 0) {
        std::cout << "Success!" << std::endl;
    }
    else {
        std::cout << "Fail!" << std::endl;
        return -1;
    }

    return 0;
}
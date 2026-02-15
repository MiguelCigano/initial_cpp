#include <iostream>
#include <vector>
#include <utility> // std::pair

int main() {
    std::vector<int> A = {1, 2, 3, 4};
    std::vector<int> B = {1, 2, 3, 4};

    // Relación R: "a está relacionado con b si a < b"
    std::vector<std::pair<int, int>> R;

    for (auto a : A) {
        for (auto b : B) {
            if (a < b) {
                R.push_back({a, b});
            }
        }
    }
    
    // Leer la relación
    std::cout << "Relacion R = {(a,b) | a < b} : " << std::endl;
    for (auto p : R) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}

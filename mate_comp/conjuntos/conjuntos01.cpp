#include <iostream>
#include <vector> // Clase Vector - Dinamicos
#include <algorithm>
#include <array> // Clase Array - Estaticos

int main() {

    std::cout << "+------------------+" << std::endl;
    std::cout << "Usando Arrays: " << std::endl;
    std::cout << "+------------------+" << std::endl;
    // std::array<int, 3> A_ = {1, 2, 3};
    auto A_ = std::array<int, 3> {1, 2, 3};

    for (size_t i = 0; i < A_.size(); i++) {
        std::cout << A_[i] << std::endl;
    }

    std::cout << "+------------------+" << std::endl;
    std::cout << "Usando Vectors: " << std::endl;
    std::cout << "+------------------+" << std::endl;

    std::vector<int> A = {1, 2, 4};
    std::vector<std::string> B = {"a", "b", "c", "d"};
    // std::vector<std::string> B;

    std::cout << "Permutaciones de A:" << std::endl;

    std::cout << "Conjunto A = { ";

    for (int elem : A) {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "Elementos en A = " << A.size() << std::endl;

    std::cout << "Conjunto B = { ";

    for (std::string elem : B) {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "+------------------+" << std::endl;
    std::cout << "Permutaciones: " << std::endl;
    std::cout << "+------------------+" << std::endl;
    do {
        for (std::string x : B) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(B.begin(), B.end()));

    return 0;
}
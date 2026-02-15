#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> relationship_auto(const std::vector<int> &A, const std::vector<int> &B) {
    std::vector<std::pair<int, int>> R;

    for (const auto &a : A) {
        for (const auto &b : B) {
            if (a <= b) {
                R.push_back({a, b});
            }
        }
    }

    return R;
}

void print_auto(const std::vector<std::pair<int, int>> &R) {
    for(auto &p : R) {
        std::cout << "fn2 : (" << p.first << ", " << p.second << ")" << std::endl;
    }
}

int main() {
    std::vector<int> A = {1, 3, 3, 0, 3};
    std::vector<int> B = {0, 2, 2, 0, 0};

    std::vector<std::pair<int, int>> R = relationship_auto(A, B);
    print_auto(R);
    
    // for (auto p : R) {
    //     std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    // }

    return 0;
}
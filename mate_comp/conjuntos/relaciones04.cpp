#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<std::string, std::string>> relationship_auto(const std::vector<std::string> &A, const std::vector<std::string> &B) {
    std::vector<std::pair<std::string, std::string>> R;

    for (const auto &a : A) {
        for (const auto &b : B) {
            if (a == b) {
                R.push_back({a, b});
            }
        }
    }

    return R;
}

void print_auto(const std::vector<std::pair<std::string, std::string>> &R) {
    for(auto &p : R) {
        std::cout << "fn3 : (" << p.first << ", " << p.second << ")" << std::endl;
    }
}

int main() {
    std::vector<std::string> A = {"x", "y", "w", "b", "c", "a"};
    std::vector<std::string> B = {"a", "a", "a", "a", "a"};

    std::vector<std::pair<std::string, std::string>> R = relationship_auto(A, B);
    print_auto(R);
    
    return 0;
}
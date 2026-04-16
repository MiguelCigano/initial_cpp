#include <map>
#include <string>
#include <iostream>

std::pair<int, bool> check_sensor() {
    return {25, true};
}

int main() {
    std::map<std::string, int> scores = {{"Alice", 19}, {"John", 25}};
    
    struct Point {
        int x;
        int y;
    };

    // Structured binding
    // Range-based for loop for (declaration : range)
    for (const auto& [name, score] : scores) {
        std::cout << name << ": " << score << std::endl;
    }

    // Work with Structs
    Point p{10, 11};
    auto [px, py] = p; // Unpackaging
    std::cout << "x: " << px << ", y: " << py << std::endl;

    auto [val, status] = check_sensor();

    std::cout << val << ", " << status << std::endl;

    return 0;
}


